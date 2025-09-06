#include <ncurses.h>
#include <iostream>

#include "texed/textFile.h"

int main(int argc, char** argv) {
    // initscr();

    // start_color();

    // // Code goes here

    // getch();

    // endwin();


    texed::textFile myTextFile(argv[1]);

    myTextFile.buffer.push_back("Hello, World!");

    myTextFile.writeBuffer();

    return 0;
}
