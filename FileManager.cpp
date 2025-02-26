#include <filesystem>
#include <iostream>
#include <fstream>
#include "FileManager.hpp"
#include "FileUtils.hpp"

namespace fs = filesystem;

FileManager::FileManager() {
    currentPath = fs::current_path();
}

FileManager::~FileManager() {

}

void FileManager::listFiles() {
    try {
        for (auto const &entry : fs::directory_iterator(currentPath)) {
            if (fs::is_directory(entry)) {
                cout << "📂 " << entry.path().filename() << endl;
            } else {
                cout << "📄 " << entry.path().filename() << endl;
            }
        }
    } catch (const fs::filesystem_error &e) {
        cerr << "Error : " << e.what() << endl;
    }
}

void FileManager::changeDirectory(string directoryPath) {

    try {
        if (fs::exists(directoryPath) && fs::is_directory(directoryPath)) {
        
            fs::current_path(directoryPath);
            currentPath = fs::current_path();
            cout << currentPath << endl;

        } else {

            cout << "Dossier Introuvable" << endl;

        }
    } catch (const fs::filesystem_error &e) {
        cerr << "Erorr : " << endl;
    }
}

void FileManager::createFiles(string command) {

    vector<string>arg = split(command, " ");

    if (arg[0] == "file") {

        ofstream fst(arg[1]);
        cout << "fichier " << arg[1] << " créer avec succès" << endl;
        fst.close();

    } else if (arg[0] == "dir") {
        if (fs::create_directory(arg[1])) {
            cout << "dossier " << arg[1] << " créer avec succès" << endl;
        } else {
            cout << "erreur lors de la création du dossier" << arg[1] << endl;
        }
    }
}