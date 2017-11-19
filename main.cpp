#include "main.h"

std::map<std::string, stVariable> variables;

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

std::string geDescription(std::string varName)
{
	return variables[varName].description;
}

std::deque<std::string> geVariants(std::string varName)
{
	return variables[varName].variants;
}

std::deque<std::string> &geVariantsRef(std::string varName)
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

void prepareFile(CFileText *file)
{
	for(size_t i = 0; i < file->count(); ++i){
		for (auto var : variables){
			if (file->at(i).find("${" + var.first + "}") != std::string::npos)
				file->at(i) = stringReplace(file->at(i), "${" + var.first + "}", var.second.variants[var.second.variant]);
		}
	}
}
