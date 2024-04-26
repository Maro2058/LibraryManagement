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

/* To Do List:
 * Genre:
 *   Change Genre from enum, to user defined list.
 *   Add Base Genres
 *
 * Make it so there can't be more than one account with the same ID (cout << "ID already exists";)  DONE
 *
 * Make it so there can't be more than one book with the same ISBN (cout << "ISBN already exists" << endl <<
 * "Do you want to add copies?";)
 *
 * Make a function (with function overloading) for printing books / members / loans.
 *
 * Make it so there can't be a loan request if there are no available copies.
 * (Or Maybe Don't. Depends on Amr's Implementation)
 *
 * Generate reports function in librarian class
 *
 * Comment Code (+ fix old comments)
 *
 */



int main() {
        /*void addBook();
        void removeBook();
        void updateBook();
        void viewMembers();
        void addMember();
        void removeMember();
        void processLoanRequest();
        8. void generateReports();
        9. log out;
        */


        int option = 0;
        int bookOption = 0;
        int memberOption;
        theuser = theuser->login();

        cout << "Welcome " << theuser->getname() << endl;
        if (typeid(*theuser) == typeid(Librarian)) {
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
                    theuser->manageBooks();
                } else if (option == 2) {
                    theuser->manageMembers();
                } else if(option == 3){
                    theuser->processLoanRequest();
                } else if(option == 4) {
                    theuser->generateReports();
                }else if(option == 5) {
                    theuser->manageAccount();
                }else if (option == 6) {
                    //Do nothing.
                }else {
                    cout << "Invalid Input" << endl;
                }
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
            }
        } else if (typeid(*theuser) == typeid(Student)) {
            cout << "1. Request loan"<<endl;
            cout << "2. Return Book"<<endl;

            cin >> option;
            switch(option)
            {
                case 1:
                    theuser->requestLoan();
                    break;
                case 2:
                    theuser->returnBook();
                    break;
                default:
                    break;
            }
        }
}