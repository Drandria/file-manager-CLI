#include "FileManager.hpp"
#include <filesystem>
#include <iostream>

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