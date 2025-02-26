#include <iostream>
#include <filesystem>
#include "FileManager.hpp"
#include "FileUtils.hpp"
#include <vector>

using namespace std;
namespace fs = filesystem;

int main () {
    string command;
    FileManager fm = FileManager();

    while (true) {
        cout << "> ";
        getline(cin, command);

        if (command == "list") {

            fm.listFiles();

        } else if (command == "exit") {

            break;

        } else if (command.substr(0, 3) == "cd ") {

            string dir = command.substr(3);
            fm.changeDirectory(dir);

        } else if (command.substr(0,7) == "create ") {

            fm.createFiles(command.substr(7));

        } else{

            cout << "Commande inconnue" << endl;
            
        }

        cout << endl;

    }

    return 0;
}