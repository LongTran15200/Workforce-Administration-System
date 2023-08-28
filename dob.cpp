#include <iostream>
#include <exception>
#include "dob.h"
using namespace std;
void validateDate(int month, int day, int year) {
    if (day == 0 || day > 31)
        throw InvalidDay();

    if (month == 1 && day > 31)
        throw InvalidDay();
    else if (month == 2 && day > 28)
        throw InvalidDay();
    else if (month == 3 && day > 31)
        throw InvalidDay();
    else if (month == 4 && day > 30)
        throw InvalidDay();
    else if (month == 5 && day > 31)
        throw InvalidDay();
    else if (month == 6 && day > 30)
        throw InvalidDay();
    else if (month == 7 && day > 31)
        throw InvalidDay();
    else if (month == 8 && day > 31)
        throw InvalidDay();
    else if (month == 9 && day > 30)
        throw InvalidDay();
    else if (month == 10 && day > 31)
        throw InvalidDay();
    else if (month == 11 && day > 30)
        throw InvalidDay();
    else if (month == 12 && day > 31)
        throw InvalidDay();
    else if (month > 12)
        throw InvalidMonth();
}

bool isValidDate(int month, int day, int year) {
    try {
        validateDate(month, day, year);
        return true;
    }
    catch (InvalidDay&) {
        cout << "Invalid day. Please try again." << endl;
        return false;
    }
    catch (InvalidMonth&) {
        cout << "Invalid month. Please try again." << endl;
        return false;
    }
}


