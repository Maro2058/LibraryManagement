/*#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>
#include <algorithm> // for std::all_of
#include <cctype>    // for std::isdigit
#include <vector>*/
#include "LibraryManagement.h"

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

    Member* member = nullptr;
    member =  member->login();
    member->addBook();
    member->addMember();
}