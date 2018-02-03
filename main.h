#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <string>
#include <regex>
#include <deque>
#include <map>

#include <boost/filesystem.hpp>

#include "FileMan/cfiletext.h"
#include "FileMan/cfileinfo.h"
#include "FileMan/cfileini.h"

struct stVariable{
	size_t default_variant = 0;
	size_t variant = 0;
	std::deque<std::string> variants;
	std::string description;
};

extern std::map<std::string, stVariable> variables;
extern std::string wizard_file;
extern std::deque<CFileInfo> list_project;
extern std::deque<std::string> list_exclude;
extern std::deque<std::string> list_asIs;
extern std::deque<std::string> list_rename;

void resetVariables();
void addVariable(std::string name, std::deque<std::string> variants, std::string description = "");
void setDescription(std::string varName, std::string description);
void setVariants(std::string varName, std::deque<std::string> variants);
void addVariant(std::string varName, std::string variant);
void setDefaultVariant(std::string varName, size_t id);

stVariable getVariable(std::string name);
std::string getDescription(std::string varName);
std::deque<std::string> getVariants(std::string varName);
std::deque<std::string> &getVariantsRef(std::string varName);
size_t getDefaultVariant(std::string varName);

void selectVariant(std::string varName, size_t id);
size_t getSelectedVariant(std::string varName);

std::string stringReplace(std::string str, const std::string &old_substr, const std::string &new_substr);


void prepareString(std::string *str);
void prepareFile(CFileText *file);


std::deque<CFileInfo> make_list_wizard(const boost::filesystem::path &  path);


void setWizard(std::string file);
void setProject(std::deque<CFileInfo> list);
void setExclude(std::deque<std::string> list);
void setAsIs(std::deque<std::string> list);
void setRename(std::deque<std::string> list);

void createProject(std::string projectPath);

#endif //MAIN_H
