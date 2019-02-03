#include "ConfigParser.h"

//include -std=c++11 while compiling

int main()
{
    bool checkConfigFile;
    ConfigParser configParser("configure.config");

    checkConfigFile = configParser.parseFile();

    if (checkConfigFile)
    {

        // for (std::unordered_map<std::string, std::string>::const_iterator it = configParser.parameters.begin();
        //      it != configParser.parameters.end(); ++it)
        // {

        //     std::cout << it->first << " : " << it->second << std::endl;
        // }
        std::cout << configParser.getValue("test4") << std::endl;
    }
    else
    {
        std::cout << "Please Check file" << std::endl;
    }
}