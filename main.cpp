/*#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>
#include <algorithm> // for std::all_of
#include <cctype>    // for std::isdigit
#include <vector>*/
#include "LibraryManagment.h"

/* To Do List:
 * Genre:
 *   Change Genre from enum, to user defined list.
 *   Add Base Genres
 *   return book function in student class
 *   process loan request function at librarian class
 *   generate reports function in librarian class
 *
 * Reading from Books:
 *   Currently 3 different versions of the same code
 *   Unify all into 1
 */




int main()
{

    Librarian morad;
    morad.addBook();
    morad.viewMembers();
    morad.addMember();
    morad.removeMember();


    return 0;
}