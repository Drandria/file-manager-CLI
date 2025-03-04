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
        void createFiles(string command);
        void renameFiles(string command);
        void removeFiles(string name);
};

#endif