#include <iostream>
#include <string>
#include <cstdlib> // For exit() function
#include <conio.h> // For _getch()
#include <windows.h> // For Sleep()
#include <algorithm> // For transform()

using namespace std;

//Converting capital to lower
string toLowerCase(const string& str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

void login() {
    system("cls");
    char ch;
    const int maxAttempts = 3;
    int attemptCount = 0;
    string user, pass;

    while (attemptCount < maxAttempts) {
        cout << "\n\n\n\n\n";
        cout << "\t\t\t\t\t\t===============================" << endl;
        cout << "\t\t\t\t\t\t|                             |" << endl;

        // Print title with borders
        cout << "\t\t\t\t\t\t|   ";
        cout << "\tLogin Process";
        cout << "\t      |" << endl;

        // Print bottom border
        cout << "\t\t\t\t\t\t|                             |" << endl;
        cout << "\t\t\t\t\t\t===============================" << endl;
        cout << "\n\n\n Enter User/Email : ";
        getline(cin, user);
        cout << "\n\n Enter Password : ";

        pass.clear(); //Clear the password string for each new input
        ch = _getch();
        while (ch != 13) { // Enter key
            if (ch == 8) { // Backspace key
                if (!pass.empty()) {
                    pass.pop_back();
                    cout << "\b \b";
                }
            }
            else {
                pass += ch;
                cout << "*";
            }
            ch = _getch();
        }
        cout << endl;

        // Convert username to lowercase for case-insensitive comparison
        string lowerUser = toLowerCase(user);

        // Check for successful login
        if ((lowerUser == "long.tran832@gmail.com" || lowerUser == "longtran832") && pass == "admin") {
            cout << "\n\n\n\t\tCongratulation! Login Successfully!";
            cout << "\n\n\n\t\t\t\t\tLoading";
            for (int i = 1; i <= 6; i++) {
                Sleep(500);
                cout << ".";
            }
            return; //Exit the function on successful login
        }
        else {
            attemptCount++; // Increment the attempt counter
            int attemptsRemaining = maxAttempts - attemptCount;

            if (attemptCount == 2) {
                cout << "Hint: -- Consider who typically manages system settings. --";
            }
            if (attemptCount == maxAttempts) {
                cout << "\n\nToo many failed attempts. Exiting...";
                Sleep(2000); // Wait for a short time before exiting
                exit(1); //Exit the program with a non-zero status
            }

            //Provide specific feedback if username or password is incorrect
            if (lowerUser != "long.tran832@gmail.com" && lowerUser != "longtran832" && pass != "admin") {
                cout << "\n\nBoth Username and Password are Incorrect.";
            }
            else if (lowerUser != "long.tran832@gmail.com" && lowerUser != "longtran832") {
                cout << "\n\nUsername is Incorrect.";
            }
            else {
                cout << "\n\nPassword is Incorrect.";
            }

            cout << " Attempts remaining: " << attemptsRemaining << endl;
            cout << "\nPress any key to continue...";
            _getch();
            system("cls"); //Clear the screen before asking for input again
        }
    }
}
