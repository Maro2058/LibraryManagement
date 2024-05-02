/*#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>
#include <algorithm> // for std::all_of
#include <cctype>    // for std::isdigit
#include <vector>*/
#include "LibraryManagement.h"
#include "LibraryManagementImplementation.cpp"

int main() {
    int option = 0;
    int bookOption = 0;
    int memberOption;
    Member* user = nullptr;


    string tempID;
    string tempPass;
    cout << "Enter User ID: ";
    getline(cin, tempID);
    cout << "Enter Password: ";
    getline(cin, tempPass);

    user->loginGui(tempID, tempPass);
    user = user->login(tempID, tempPass);

    cout << "Welcome " << user->getname() << endl;
    if (typeid(*user) == typeid(Librarian)) {
        cout << "Please choose one of the below options" << endl;
        while (option != 6) {
            cout << "1: Manage Books" << endl;
                    //cout << "1: Add Book" << endl;
                    //cout << "2: Remove Book" << endl;
                    //cout << "3: Update Book" << endl;
                    //cout << "4: Search Books " << endl;
                    //cout << "5: View Books" << endl;
                    //cout << "6: Back" << endl;
            cout << "2: Manage Members" << endl;
                    //cout << "1: View Members" << endl;
                    //cout << "2: Add Members" << endl;
                    //cout << "3: Remove Members" << endl;
                    //cout << "4: Back" << endl;
            cout << "3: Loan Requests"<< endl;
            cout << "4: Generate Report" << endl;
            cout << "5: Account Settings" << endl;
            cout << "6: Quit" << endl;

            //use cases you caveman
            cin >> option;
            if (option == 1) {
                user->manageBooks();
            } else if (option == 2) {
                user->manageMembers();
            } else if(option == 3){
                user->processLoanRequest();
            } else if(option == 4) {
                user->generateReports();
            }else if(option == 5) {
                user->manageAccount();
            }else if (option == 6) {
                //Do nothing.
            }else {
                cout << "Invalid Input" << endl;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
    } else if (typeid(*user) == typeid(Student)) {
        while (option != 5) {
            cout << "1. Request loan"<<endl;
            cout << "2. Return Book"<<endl;
            cout << "3. Account Settings"<<endl;
            cout << "4. UserReport"<<endl;

            cout << "5. Quit"<<endl;


            cin >> option;
            switch(option)
            {
                case 1:
                    user->requestLoan();
                break;
                case 2:
                    user->returnBook();
                    break;
                case 3:
                    user->manageAccount();
                break;
                case 4:
                    user->UserReport();
                break;
                default:
                    break;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
    } else {
        cout << "This username does not exist" << endl;
    }

}