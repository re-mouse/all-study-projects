#include <iostream>
#include <sstream>
#include <regex>
#include <fstream>

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cerr << "Argument error" << std::endl;
        return (-1);
    }
    std::string fname = argv[1];
    std::string whatReplace = argv[2];
    std::string toReplace = argv[3];
    std::ifstream file(fname);
    if (!file.is_open())
    {
        std::cerr << "Can't open file" << std::endl;
        return (-1);
    }
    std::stringstream strStream;
    strStream << file.rdbuf();
    std::string strFile = strStream.str();
    size_t findRes = 0;
    while ((findRes = strFile.find(whatReplace, findRes)) != std::string::npos)
        strFile.replace(findRes, whatReplace.length(), toReplace);
    std::ofstream replaceFile(fname + ".replace");
    if (!replaceFile.is_open())
    {
        std::cerr << "Can't open replace file" << std::endl;
        return (-1);
    }
    replaceFile << strFile;
    file.close();
    replaceFile.close();
}