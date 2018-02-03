#include "main.h"

using namespace boost::filesystem;

std::map<std::string, stVariable> variables;
std::string wizard_file;
std::deque<CFileInfo> list_project;
std::deque<std::string> list_exclude;
std::deque<std::string> list_asIs;
std::deque<std::string> list_rename;

void resetVariables()
{
    variables.clear();
}

void addVariable(std::string name, std::deque<std::string> variants, std::string description)
{
	stVariable var;
	var.variants = variants;
	var.description = description;
	variables[name] = var;
}

void setDescription(std::string varName, std::string description)
{
	variables[varName].description = description;
}

void setVariants(std::string varName, std::deque<std::string> variants)
{
	variables[varName].variants = variants;
}

void addVariant(std::string varName, std::string variant)
{
	variables[varName].variants.push_back(variant);
}

void setDefaultVariant(std::string varName, size_t id)
{
	variables[varName].default_variant = id;
}

stVariable getVariable(std::string name)
{
	return variables[name];
}

std::string getDescription(std::string varName)
{
	return variables[varName].description;
}

std::deque<std::string> getVariants(std::string varName)
{
	return variables[varName].variants;
}

std::deque<std::string> &getVariantsRef(std::string varName)
{
	return variables[varName].variants;
}

size_t getDefaultVariant(std::string varName)
{
	return variables[varName].default_variant;
}

void selectVariant(std::string varName, size_t id)
{
	variables[varName].variant = id;
}

size_t getSelectedVariant(std::string varName)
{
	return variables[varName].variant;
}

std::string stringReplace(std::string str, const std::string &old_substr, const std::string &new_substr)
{
	size_t find_pos = 0;
	while (true){
		size_t pos = str.find(old_substr, find_pos);
		if (pos == std::string::npos)
			break;
		str.replace(pos, old_substr.length(), new_substr);
		find_pos = pos + new_substr.length();
	}
	return str;
}

void prepareString(std::string *str)
{
	for (auto var : variables){
		if (str->find("%{" + var.first + "}") != std::string::npos)
			*str = stringReplace(*str, "%{" + var.first + "}", var.second.variants[var.second.variant]);
	}
}

void prepareFile(CFileText *file)
{
	for(size_t i = 0; i < file->count(); ++i){
//		for (auto var : variables){
//			if (file->at(i).find("${" + var.first + "}") != std::string::npos)
//				file->at(i) = stringReplace(file->at(i), "${" + var.first + "}", var.second.variants[var.second.variant]);
//		}
		prepareString(&file->at(i));
	}
}

std::deque<CFileInfo> make_list_wizard(const path &  path){
	std::deque<CFileInfo> result;
	directory_iterator end_itr; // default construction yields past-the-end
		for ( directory_iterator itr( path );
			 itr != end_itr;
		++itr )
			 {
				 if ( is_directory( *itr ) )
				 {
					 std::deque<CFileInfo> subdir = make_list_wizard( *itr );
					 for (auto file : subdir)
						 result.push_front(file);
				 }
				 		result.push_front(CFileInfo((*itr).path().string()));
			 }
			 	return result;
}

void setWizard(std::string file)
{
	wizard_file.clear();
	wizard_file = file;
}

void setProject(std::deque<CFileInfo> list)
{
	list_project.clear();
	list_project = list;
}

void setExclude(std::deque<std::string> list)
{
	list_exclude.clear();
	list_exclude = list;
}

void setAsIs(std::deque<std::string> list)
{
	list_asIs.clear();
	list_asIs = list;
}

void setRename(std::deque<std::string> list)
{
	list_rename.clear();
	list_rename = list;
}

template<typename T>
static bool hasInDeque(std::deque<T> &deq, const T &value){
	for(auto it : deq)
		if (it == value)
			return true;
		return false;
}

void createProject(std::string projectPath)
{
	std::string projectName = getVariable("ProjectName").variants.front();
	CFileInfo wizard(wizard_file);
	
	create_directory(path(projectPath + projectName));
	for (auto file : list_project){
		std::string fileName = file.file();
		fileName.erase(0, wizard.path().length());

		if (fileName == wizard.fullName())
			continue;

		if (hasInDeque(list_exclude, fileName))
			continue;

		if (is_directory( path(file.file()) )){
			create_directories(path(projectPath + projectName + "/" + fileName));
			continue;
		}

		try {
			copy_file(path(file.file()), path(projectPath + projectName + "/" + fileName));
		} catch (std::exception) {
			create_directories(path(CFileInfo(projectPath + projectName + "/" + fileName).path()));
			copy_file(path(file.file()), path(projectPath + projectName + "/" + fileName));
		}
				if (hasInDeque(list_asIs, file.file()))
			continue;

		const std::regex re(R"(\"(.+)\"\s+\"(.+)\")");
		std::cmatch m;
		for (auto &name_pair : list_rename){
			if (std::regex_match(name_pair.c_str(), m, re)){
				if (m[1].str() == fileName){
					std::string targetName = m[2].str();
					prepareString(&targetName);
					boost::filesystem::rename(path(projectPath + projectName + "/" + fileName), path(projectPath + projectName + "/" + targetName));
					fileName = targetName;
					break;
				}
			}
		}

		CFileText text(projectPath + projectName + "/" + fileName);
		prepareFile(&text);
		std::cout << "Prepare " + fileName << std::endl;
	}
}
