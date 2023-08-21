#pragma once
#include <string>

class Employee {
private:
    int emp_id, sal, group_id,dob;
    std::string name, address;

public:
    void menu();
    void insert();
    void display();
    void search();
    //void modify();
};
