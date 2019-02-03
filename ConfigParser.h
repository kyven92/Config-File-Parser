#ifndef CONFIGEXTRATOR_H
#define CONFIGEXTRATOR_H

#include <iostream>
#include <unordered_map>


class ConfigParser {

private:
std::string filePath;
std::string delimeter;

bool parseAndAddToUmap(std::string line);
void addToUMap(std::string key, std::string value);

public:
//include -std=c++11 as an argument with compiling command
std::unordered_map<std::string,std::string> parameters;

ConfigParser();
ConfigParser(std::string filePath);
ConfigParser(std::string filePath, std::string delimeter);

bool parseFile();
bool parseFile(std::string filePath);

std::string getValue(std::string key);


};

#endif