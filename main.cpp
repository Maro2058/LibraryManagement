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
 * Three global Vectors that store all the Books/Members/Outgoing Loans.
 *
 * Modify Code to work with three global vectors instead of reading in each function.
 *      Read From file to vector on runtime, and whenever the file is modified.
 */



int main()
{
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

    Librarian librarian;
    librarian.addMember();
    int option = 0;
    Member* member = nullptr;
    member = member->login();
    if (member->getrole() == 0) {
        cout << "Please choose one of the below options" << endl;
        while (option != 9) {
            cout << "1: Add Book" << endl;
            cout << "2: Remove Book" << endl;
            cout << "3: Update Book" << endl;
            cout << "4: View Members" << endl;
            cout << "5: Add Members" << endl;
            cout << "6: Remove Members" << endl;
            cout << "7: Process Loan Requests" << endl;
            cout << "8: Generate Report" << endl;
            cout << "9: Manage Account" << endl;
            cout << "10: Quit" << endl;

            cin >> option;
            if (option == 1) {
                member->addBook();
            } else if (option == 2) {
                member->removeBook();
            } else if (option == 3) {
                member->updateBook();
            } else if (option == 4) {
                member->viewMembers();
            } else if (option == 5) {
                member->addMember();
            } else if (option == 6) {
                member->removeMember();
            } else if (option == 7) {
                member->processLoanRequest();
            } else if (option == 8) {
                member->generateReports();
            } else if (option == 9) {
                member->manageAccount();
            } else if (option == 10) {
                return 0;
            } else {
                cout << "Invalid Input" << endl;
            }
        }
    } else if (member->getrole() == 1) {
        cout << "Haven't coded this part yet"<<endl;
    }

}