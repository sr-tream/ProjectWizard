#include <iostream>
#include <boost/filesystem.hpp>
#include <regex>

#include "../main.h"
#include "../FileMan/cfileinfo.h"
#include "../FileMan/cfileini.h"

using namespace boost::filesystem;

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
		result.push_front(CFileInfo((*itr).path().c_str()));
	}
	return result;
}

std::string getProjectName(std::string defName = "default"){
	std::string name;

	std::cout << "Input project name [" + defName + "]: ";
	//std::cin >> name;
	getline(std::cin, name);

	if (name.empty())
		name = defName;

	addVariable("ProjectName", {name}, "The project name");
	create_directory(path(name));
	return name;
}

template<typename T>
bool hasInDeque(std::deque<T> &deq, const T &value){
	for(auto it : deq)
		if (it == value)
			return true;
	return false;
}

int main(int args, char **argv)
{
	if (args < 2){
		std::cout << "Wizard does not selected" << std::endl;
		return 1;
	}

	CFileInfo wizFile(argv[1]);
	if (!wizFile.isExist()){
		// TODO: Create new wizard
		std::cout << "wizard \"" << wizFile.fullName() << "\" not exist" << std::endl;
		return 2;
	}

	CFileIni config(argv[1]);

	std::deque<CFileInfo> list_wizard = make_list_wizard(path(wizFile.path()));
	std::deque<std::string> ex_files = config.array("/exclude");
	std::deque<std::string> as_is = config.array("/AsIs");
	std::deque<std::string> rename = config.array("/rename");

	std::string defName = config.value("/ProjectName");
	std::string ProjectName = "default";
	if (args == 2)
		ProjectName = getProjectName(defName.empty() ? "default" : defName);
	else {
		ProjectName = argv[2];
		addVariable("ProjectName", {ProjectName}, "The project name");
		create_directory(path(ProjectName));
	}

	std::deque<std::string> vars = config.array("/variable");
	for (auto &var : vars){ // TODO: bind args to variables
		std::string description = config.value(var + "/description");
		std::string defVariant = config.value(var + "/default_variant");
		int input = config.read<int>(var + "/input");
		std::deque<std::string> variants = config.array(var + "/variant");
		if (variants.empty())
			variants.push_back(defVariant);

		addVariable(var, variants, description);

		std::cout << var + ":" << std::endl;
		if (!description.empty())
			std::cout << description << std::endl;

		if (!input){
			size_t id = 0;
			for (size_t i = 0; i < variants.size(); ++i){
				if (variants[i] == defVariant)
					id = i;
				std::cout << "\t" << i <<". " + variants[i] << std::endl;
			}

			setDefaultVariant(var, id);
			std::cout << "Select variant [" << id << "]: ";
			std::string strId;
			getline(std::cin, strId);
			try {
				id = std::stoul(strId);
			} catch (std::exception) { }
			selectVariant(var, id);
		}
		else{
			setDefaultVariant(var, 0);
			selectVariant(var, 0);
			std::cout << "Input value [" << defVariant << "]: ";
			std::string value;
			getline(std::cin, value);
			if (value.empty())
				value = defVariant;
			variants.push_front(value);
			setVariants(var, variants);
		}
	}

	for (auto file : list_wizard){
		std::string fileName = file.file();
		fileName.erase(0, wizFile.path().length());

		if (fileName == wizFile.fullName())
			continue;

		if (hasInDeque(ex_files, fileName))
			continue;

		if (is_directory( path(file.file()) )){
			create_directories(path(ProjectName + "/" + fileName));
			continue;
		}

		try {
			copy_file(path(file.file()), path(ProjectName + "/" + fileName));
		} catch (std::exception) {
			create_directories(path(CFileInfo(ProjectName + "/" + fileName).path()));
			copy_file(path(file.file()), path(ProjectName + "/" + fileName));
		}
		if (hasInDeque(as_is, file.file()))
			continue;

		const std::regex re(R"(\"(.+)\"\s+\"(.+)\")");
		std::cmatch m;
		for (auto &name_pair : rename){
			if (std::regex_match(name_pair.c_str(), m, re)){
				if (m[1].str() == fileName){
					std::string targetName = m[2].str();
					prepareString(&targetName);
					boost::filesystem::rename(path(ProjectName + "/" + fileName), path(ProjectName + "/" + targetName));
					fileName = targetName;
					break;
				}
			}
		}

		CFileText text(ProjectName + "/" + fileName);
		prepareFile(&text);
		std::cout << "Prepare " + fileName << std::endl;
	}

	return 0;
}
