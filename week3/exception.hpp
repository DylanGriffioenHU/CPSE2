//
// Created by dylan on 3-3-2020.
//

#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <exception>
#include <string>

//Exception that get's thrown when the end of the file is reached
class end_of_file final : public std::exception{
public:
    const char* what() const noexcept override {
        return message.c_str();
    }

private:
    std::string message = "end of file";
};
//Expectin that is thrown when the color in the txt file is not know to the factory
class unknown_color final : public std::exception{
public:
    unknown_color(const std::string & name):
        message( std::string( "unknown color [") + name + "]")
    {}

    const char* what() const noexcept override {
        return message.c_str();
    }

private:
std::string message;
};

//exception thrown when the shape in the txt file is not known to the factory
class unknown_shape final : public std::exception{
public:
    unknown_shape(const std::string & name):
        message( std::string( "unknown shape [") + name + "]")
    {}

    const char* what() const noexcept override {
        return message.c_str();
    }

private:
std::string message;
};

//Exception thrown when the position in the txt file is not valid
class invalid_position final : public std::exception{
public:
    invalid_position(const char & name):
        message( std::string( "invalid position [") + name + "]")
    {}

    const char* what() const noexcept override {
        return message.c_str();
    }

private:
std::string message;
};

#endif