// textFile.h

// Text file represented by a buffer and its name,
// with operations to read and write files

// edwardo37 9/6/25

#pragma once

#include <string>
#include <vector>

namespace texed {

enum class errorCode {
    success,
    cancelled,

    notRegularFile,
    openingFile
};

class textFile {
public:
    std::vector<std::string> buffer;

    const static size_t NAME_MAX_SIZE = 255;

    char name[NAME_MAX_SIZE+1];

    // Open/create file on initialization
    // If filename is empty or none provided, start with none
    textFile(const char* fileToOpen);
    textFile();

    // Write buffer to filepath in 'name'
    // If 'name' is empty, ask user for name
    // Returns error code relating to status
    errorCode writeBuffer();
    
    // Overwrite buffer without confirming
    // Returns error code relating to status
    errorCode overwriteBuffer(const char* newFileName);
};

}
