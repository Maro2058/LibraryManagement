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
 * Replace all appropriate parts of code with ReadFile Function
 *
 * Make it so there can't be more than one account with the same ID (cout << "ID already exists";)
 *
 * Make it so there can't be more than one book with the same ISBN (cout << "ISBN already exists" << endl <<
 * "Do you want to add copies?";)
 *
 * Make a function (with function overloading) for printing books / members / loans.
 *
 * Make it so there can't be a loan request if there are no available copies
 *
 * Return book function in student class
 *
 * Process loan request function at librarian class
 *
 * Generate reports function in librarian class
 *
 * Write ReadFile Function for Loan.txt
 *
 * Comment Code (+ fix old comments)
 */

int main()
{

    /*Librarian morad;
    morad.addBook();
    morad.viewMembers();
    morad.addMember();
    morad.removeMember();
*/

    Student Amr;
    Amr.requestLoan();

    return 0;
}