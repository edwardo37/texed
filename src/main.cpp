#include <ncurses.h>

#include <iostream>
#include <string>

#include "texed/textFile.h"

int main(int argc, char** argv) {
    // initscr();

    // start_color();

    // // Code goes here

    // getch();

    // endwin();

    // Using empty string is the same as default constructor
    texed::textFile myTextFile(argv[1] ? argv[1] : "");

    myTextFile.buffer.push_back("Hello, World!");
    myTextFile.buffer.push_back("");
    myTextFile.buffer.push_back("I love burga.");

    texed::errorCode writeBufferError = myTextFile.writeBuffer();

    if (writeBufferError == texed::errorCode::cancelled) {
        std::cerr << "Overwriting file cancelled." << std::endl;
    }
    else if (writeBufferError == texed::errorCode::notRegularFile) {
        std::cerr << "File specified is not regular file." << std::endl;
    }
    else if (writeBufferError == texed::errorCode::openingFile) {
        std::cerr << "Error opening file." << std::endl;
    }

    return 0;
}
