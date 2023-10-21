#include "FileExceptions.h"

FileOpenException::FileOpenException(const std::string& filename)
    : filename(filename) { }

const char* FileOpenException::what() const noexcept {
    return ("Error: Unable to open the file '" + filename + "' for reading or writing.").c_str();
}

FileReadException::FileReadException(const std::string& filename)
    : filename(filename) { }

const char* FileReadException::what() const noexcept {
    return ("Error: Unable to read data from the file '" + filename + "'.").c_str();
}
