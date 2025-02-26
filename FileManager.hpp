#ifndef FM
#define FM

#include <string>

using namespace std;

class FileManager
{
    private:
        string currentPath;
    public:
        FileManager();
        ~FileManager();
        void listFiles();
        void changeDirectory(string directoryPath);
};

#endif