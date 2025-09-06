#include <iostream>
#include <fstream>

#include "texed/textFile.h"

// Open a text file upon creation. Creates one if not exists.
texed::textFile::textFile(const char* fileToOpen) {
    name = fileToOpen ? fileToOpen : "new.texed";

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
            std::cerr << "Error creating file..." << std::endl;
            exit(1);
        }
    }

    f.close();
}

// Write to file. Exit code 0 is success.
int texed::textFile::writeBuffer() {
    std::ofstream f(name);
    
    // Write buffer to file
    if (f.is_open()) {
        for (std::string s: buffer) {
            f << s << std::endl;
        }
    }
    else {
        std::cerr << "Error writing buffer to file..." << std::endl;
        exit(1);
    }

    f.close();

    return 0;
}
