#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include "dob.h"

using namespace std;


class Employee {
private:
	int emp_id, group_id;
	long sal;
	string name,dob,country,state,city;

public:
	void menu();
	void insert();
	void display();
	void search();
	void modify();
};

void Employee::menu() {
	p:
	system("cls");
	int input;

	cout << "\n\t\t\t\tControl Panel";
	cout << "\n\n\n 1. Insert Record";
	cout << "\n 2. Display Record";
	cout << "\n 3. Search Record";
	cout << "\n 4. Modify Record";
	cout << "\n 5. Delete Record";
	cout << "\n 6. Group Record";
	cout << "\n 7. Search Group";
	cout << "\n 8. Show All Group";
	cout << "\n 9. Exit";
	cout << "\n\nYour Choice: ";

	cin >> input;

	switch (input) {
	case 1:
		insert();
		break;
	case 2:
		display();
		break;
	case 3:
		search();
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		exit(0);
	default:
		cout <<"\n\n Invalid Value.... Please try Again....";
		cin.clear(); // Clear the error state
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
		char ignored = _getch();
		goto p;
	}
	char ignored = _getch();
	goto p;
}
void Employee::insert() {

	system("cls");
	fstream file, file1;
	cout << "\n\n\t\t\t\tInsert Record";
	cout << "\n\n\n Employee ID : ";
	cin >> emp_id;
	cin.ignore();
	cout << "\n\n\t\tName : ";
	getline(cin, name);
	std::string temp;
	int month, day, year;

	while (true) {
		std::cout << "\n\n Birthdate (mm-dd-yyyy): ";
		getline(std::cin, temp);

		if (sscanf_s(temp.c_str(), "%d-%d-%d", &month, &day, &year) != 3) {
			std::cout << "Invalid date format. Please use mm-dd-yyyy format." << std::endl;
			continue;
		}

		if (!isValidDate(month, day, year)) {
			continue; 
		}

		break;
	}
	cout << "\n\n\t\tSalary/year : ";
	cin >> sal;
	cout << "\n\n Country: ";
	cin.ignore();
	getline(cin, country);
	cout << " State: ";
	getline(cin, state);
	cout << " City: ";
	getline(cin, city);
	cout << "\n\n\t\tGroup ID : ";
	cin >> group_id;
	file.open("Employee.txt",ios::out|ios::app);
	string dob = to_string(month) + "/" + to_string(day) + "/" + to_string(year);
	file << emp_id << "\t" << name << "\t" << dob << "\t" << sal << "\t" << country<< "\t" << state << "\t" << city << "\t" << group_id << "\n";	file.close();
	file1.open("group.txt", ios::out | ios::app);
	file1 << " " << group_id << " " << emp_id << " " << sal << "\n";
	file1.close();
	cout << "\n\n\n\t\t\tNew Record Inserted Successfully...";
}
void Employee::display() {

	int empNumber = 1;
	system("cls");
	ifstream file("Employee.txt");
	cout << "\n\n\t\t\t\tDisplay Record";

	file.seekg(0, ios::end);
	 if (file.tellg() == 0) {
		 cout << "\n\n The file is empty.";
		 file.close();
		 return;
	 }	 
	 file.seekg(0, ios::beg);
	//while file is not end of the file
	 while (!file.eof()) {
		 file >> emp_id >> name >> dob >> sal >> country >> state >> city >> group_id;

		 // Print the data only if not at the end of the file
		 if (!file.eof()) {
			 cout << "\n\n Employee |" << empNumber << "| ID : " << emp_id;
			 cout << "\n\n\t\tName : " << name;
			 cout << "\n\n DOB: " << dob;
			 cout << "\n\n\t\tSalary/year : $" << sal;
			 cout << "\n\n Country: "<< country <<"\tState: " << state << "\tCity: " << city;
			 cout << "\n\n\t\tGroup ID : " << group_id;
			 cout << "\n----------------------------------------\n";
			 empNumber++;
		 }
	 }
	 char ignored = _getch();
	file.close();
	cout << "Press any button to go back to menu...";
}
void Employee::search() {

	system("cls");
	ifstream file("Employee.txt");
	file.seekg(0, ios::end);
	int emp_idd, found = 0;
	cout << "\n\n\t\t\t\tSearch Record";
	if (file.tellg() == 0) {
		cout << "\n\n The file is empty.";
		file.close();
		return;
	}
	cout << "\n\n Input ID number: ";
	cin >> emp_idd;
	file.seekg(0, ios::beg);
	while (!file.eof()) {
		file >> emp_id >> name >> dob >> sal >> country >> state >> city >> group_id;

		// Print the data only if not at the end of the file
		if (emp_idd == emp_id) {
			system("cls");
			cout << "\n\n\t\t\t\tSearch Record";
			cout << "\n\n Employee ID : " << emp_id;
			cout << "\n\n\t\tName : " << name;
			cout << "\n\n DOB: " << dob;
			cout << "\n\n\t\tSalary/year : $" << sal;
			cout << "\n\n Country: " << country << "\tState: " << state << "\tCity: " << city;
			cout << "\n\n\t\tGroup ID : " << group_id;
			found++;
		}
	}
	file.close();
	if (found == 0) {
		cout << "\n\n Cannot find the Employee ID... ";
	}
}

void Employee::modify() {
	system("cls");
	int sal, test_id, found = 0;
	string name1, address1;
	fstream file("Employee.txt"), file1("group.txt");
	cout << "\n\n\t\t\t\tModify Record";
	file.seekg(0, ios::end);
	file1.seekg(0, ios::end);

	if (file.tellg() == 0 || file1.tellg() == 0) {
		cout << "\n\n The file is empty.";
		file.close();
		file1.close();
		return;
	}
}
