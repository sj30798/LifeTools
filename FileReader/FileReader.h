#include <string>

namespace FileReader
{
    class BinFileReader
    {
    private:
        std::ifstream* myfile;

    public:
        BinFileReader(std::string filePath);
        ~BinFileReader();

        void ReadFileToHex(std::ostream& ostream);

    private:
        void EncodeUInt4ToHex(int byte, char* hexEncoding);
        void EncodeByteToHex(char* byte, char* hexEncoding);
    };
}
