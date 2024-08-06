#include <iostream>
#include "FileReader.h"

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cout << "ERROR: Provide file name" << std::endl;
        return 0;
    }

    std::string filePath = std::string(argv[1]);

    std::cout << "Reading file: " << filePath << std::endl;
    FileReader::BinFileReader bfr = FileReader::BinFileReader(filePath);

    bfr.ReadFileToHex(std::cout);
}
