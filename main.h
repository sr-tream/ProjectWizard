#ifndef MAIN_H
#define MAIN_H

#include <string>
#include <deque>
#include <map>

#include "FileMan/cfiletext.h"

struct stVariable{
	size_t default_variant = 0;
	size_t variant = 0;
	std::deque<std::string> variants;
	std::string description;
};

extern std::map<std::string, stVariable> variables;

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

#endif //MAIN_H
