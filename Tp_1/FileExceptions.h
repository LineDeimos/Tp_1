#pragma once
#include <string>
#include <exception>

class FileOpenException : public std::exception {
public:
    FileOpenException(const std::string& filename);

    const char* what() const noexcept override;

private:
    std::string filename;
};

class FileReadException : public std::exception {
public:
    FileReadException(const std::string& filename);

    const char* what() const noexcept override;

private:
    std::string filename;
};
