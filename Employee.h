#pragma once

class Employee {
private:
    int emp_id, group_id;
    long sal;
    std::string name,dob,country,state,city;
    

public:
    void menu();
    void insert();
    void display();
    void search();
    void modify();
    void deletion();
    void searGroup();
    void showAlGroup();
};
