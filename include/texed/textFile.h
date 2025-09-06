// textFile.h

// Text file represented by a buffer and its name,
// with operations to read and write files

// edwardo37 9/6/25

#pragma once

#include <string>
#include <vector>

namespace texed {

class textFile {
public:
    std::vector<std::string> buffer;

    std::string name;

    // Open/create file on initialization
    textFile(const char* fileToOpen);

    // Returns exit code (0 success)
    int writeBuffer();
};

}
