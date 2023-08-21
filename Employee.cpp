#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;


class Employee {
private:
	int emp_id, sal,dob, group_id;
	string name, address;

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
	cout << "\n\n\t\tEmployee Name : ";
	getline(cin, name);
	cout << "\n\n Employe DOB: ";
	cin >> dob;
	cin.ignore();
	cout << "\n\n\t\tEmployee Salary/year : ";
	cin >> sal;
	cout << "\n\n Employee Address : ";
	cin.ignore();
	getline(cin, address);
	cout << "\n\n\t\tEmployee Group ID : ";
	cin >> group_id;
	file.open("Employee.txt",ios::out|ios::app);
	file << emp_id << " " << name << " " << dob << " " << sal << " " << address << " " << group_id << "\n";	file.close();
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
		 file >> emp_id >> name >> dob >> sal >> address >> group_id;

		 // Print the data only if not at the end of the file
		 if (!file.eof()) {
			 cout << "\n\n Employee |" << empNumber << "| ID : " << emp_id;
			 cout << "\n\n\t\tEmployee Name : " << name;
			 cout << "\n\n Employe DOB: " << dob;
			 cout << "\n\n\t\tEmployee Salary/year : $" << sal;
			 cout << "\n\n Employee Address: " << address;
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
		file >> emp_id >> name >> dob >> sal >> address >> group_id;

		// Print the data only if not at the end of the file
		if (emp_idd == emp_id) {
			system("cls");
			cout << "\n\n\t\t\t\tSearch Record";
			cout << "\n\n Employee ID : " << emp_id;
			cout << "\n\n\t\tEmployee Name : " << name;
			cout << "\n\n Employe DOB: " << dob;
			cout << "\n\n\t\tEmployee Salary/year : $" << sal;
			cout << "\n\n Employee Address: " << address;
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
