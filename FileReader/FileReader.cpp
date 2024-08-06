#include "FileReader.h"
#include <iostream>
#include <fstream>

namespace FileReader
{
    BinFileReader::BinFileReader(std::string filePath)
    {
        myfile = new std::ifstream(filePath, std::ios::binary);
    }

    BinFileReader::~BinFileReader()
    {
        if (myfile && myfile->is_open())
        {
            myfile->close();
        }
    }

    void BinFileReader::ReadFileToHex(std::ostream& ostream)
    {
        char* memBlock;
        char* hexMemBlock;
        std::streampos begin, end;
        if (myfile->is_open())
        {
            begin = myfile->tellg();

            int totalBytesRead = 0;

            while (!myfile->eof())
            {
                int readSize = 10;
                memBlock = new char[readSize];
                hexMemBlock = new char[readSize*2];

                myfile->read(memBlock, readSize);

                totalBytesRead += readSize;

                for (size_t i = 0; i < readSize; i++)
                {
                    char* curHexMemBlock = hexMemBlock + sizeof(char) * 2 * i;
                    this->EncodeByteToHex(&memBlock[i], curHexMemBlock);
                }
                ostream << hexMemBlock;

                delete[] memBlock;
                delete[] hexMemBlock;
            }
        }

        //myfile->seekg(0, std::ios::beg);
    }

    void BinFileReader::EncodeUInt4ToHex(int byte, char* hexEncoding)
    {
        *hexEncoding = byte < 10 ? ('0' + byte) : ('a' + byte % 10);
    }

    void BinFileReader::EncodeByteToHex(char* byte, char* hexEncoding)
    {
        char rHexChar = *byte & 15;
        char lHexChar = (*byte >> 4) & 15;
        EncodeUInt4ToHex(lHexChar, hexEncoding);
        EncodeUInt4ToHex(rHexChar, hexEncoding + sizeof(char));
        //std::cout << (int)lHexChar << " " << (int)rHexChar << std::endl;
    }
} // namespace FileReader
