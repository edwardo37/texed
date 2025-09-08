#include <iostream>
#include <fstream>

#include <string.h>

#include <filesystem>

#include "texed/textFile.h"


texed::textFile::textFile(const char* fileToOpen) {
    // No file specified -- start fresh
    if (!*fileToOpen) {
        return;
    }

    strncpy(name, fileToOpen, NAME_MAX_SIZE);
    std::fstream f(name);

    // Attempt to open file and feed into buffer
    if (f.is_open()) {
        std::string line;
        while (std::getline(f, line)) {
            buffer.push_back(line);
        }
    }

    // Attempt to create a new file if not exists
    else {
        f.open(name, std::ios::out);
        if (!f.is_open()) {
            // TODO: add proper error handler for functions that don't return
            std::cerr << "Text File: Error initializing file..." << std::endl;
            exit(1);
        }
    }

    f.close();
}
texed::textFile::textFile() {
    textFile("");
}


texed::errorCode texed::textFile::writeBuffer() {
    // Determine name if none specified
    if (!*name) {
        // Enter new name
        std::cout << "Enter a new file name: ";
        std::cin.getline(name, NAME_MAX_SIZE);

        if (std::filesystem::exists(name)) {
            if (!std::filesystem::is_regular_file(name)) {
                return texed::errorCode::notRegularFile;
            }

            std::cout << "File exists. Overwrite? (y/N): ";
            char overwrite;
            std::cin.get(overwrite);

            if (overwrite != 'y') {
                return texed::errorCode::cancelled;
            }
        }
    }


    std::ofstream f(name);
    
    // Could not open file
    if (!f.is_open()) {
        return texed::errorCode::openingFile;
    }

    // Write buffer to file
    for (std::string s: buffer) {
        f << s << std::endl;
    }

    f.close();

    return texed::errorCode::success;
}

texed::errorCode texed::textFile::overwriteBuffer(const char* newFileName) {
    strncpy(name, newFileName, NAME_MAX_SIZE);
    name[NAME_MAX_SIZE] = '\0';

    return writeBuffer();
}
