#include <fstream>
#include <vector>
#include <iterator>
#include <boost/algorithm/string.hpp>

#include "ConfigParser.h"

using namespace std;

ConfigParser::ConfigParser()
{
}

ConfigParser::ConfigParser(std::string filePath)
{
    this->delimeter = "=";
    this->filePath = filePath;
    ConfigParser(this->filePath, this->delimeter);
}

ConfigParser::ConfigParser(std::string filePath, std::string delimeter)
{
    this->delimeter = delimeter;
    this->filePath = filePath;
}

bool ConfigParser::parseFile()
{
    return this->parseFile(this->filePath);
}

bool ConfigParser::parseFile(std::string filePath)
{
    std::ifstream fileStream(filePath);
    std::string tmpLine;
    int lineCount = 1;

    if (!fileStream.is_open())
    {
        return false;
    }

    while (getline(fileStream, tmpLine))
    {

        /*** Ignore line with white spaces ***/
        if (!tmpLine.length())
        {
            lineCount++;
            continue;
        }
        else if (tmpLine[0] == '#') // Ignore Line starting with # which are comments in the file
        {
            lineCount++;
            continue;
        }
        else
        {
            bool isLineCorrupted;
            isLineCorrupted = this->parseAndAddToUmap(tmpLine);

            if (isLineCorrupted)
            {
                std::cout << "Please Check the Line Number: " << lineCount << ": " << tmpLine << std::endl;
                return false;
            }
        }
        lineCount++;
    }
    return true;
}

bool ConfigParser::parseAndAddToUmap(std::string line)
{
    std::vector<std::string> tmpVector;

    boost::algorithm::split(tmpVector, line, boost::is_any_of(this->delimeter));

    if (tmpVector.size() == 1)
    {
        return true;
    }
    else
    {
        this->addToUMap(tmpVector[0], tmpVector[1]);
    }
    return false;
}

void ConfigParser::addToUMap(std::string key, std::string value)
{
    this->parameters[key] = value;
}

std::string ConfigParser::getValue(std::string key)
{
    std::unordered_map<std::string, std::string>::iterator it;

    it = this->parameters.find(key);

    // Check if iterator points to end of map
    if (it != this->parameters.end())
    {
        return it->second;
    }
    else
    {
        return "nf";
    }
}