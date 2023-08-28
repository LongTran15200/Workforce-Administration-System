#include <iostream>
#pragma once

void validateDate(int month, int day, int year);

bool isValidDate(int month, int day, int year);

struct InvalidDay : public std::exception {
    const char* what() const throw () {
        return "Invalid date, try again.";
    }
};

struct InvalidMonth : public std::exception {
    const char* what() const throw () {
        return "Invalid month, try again.";
    }
};
