

#ifndef LIBRARYMANAGEMENT_H
#define LIBRARYMANAGEMENT_H
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>
#include <algorithm> // for std::all_of
#include <cctype>    // for std::isdigit
#include <vector>

using namespace std;

enum Genre {
    Fiction,
    NonFiction,
    Mystery,
    Romance,
    ScienceFiction,
    Biography,
    History,
    Poetry,
    Philosophy,
    Other
};

enum Role {
    Admin,
    Student
};

std::string genreToString(Genre genre);

std::string genreToString(int genre);

class Book {
private:
    string ISBN; // Easier to use as String, otherwise it would long int, which is incompatible with some functions
    string title;
    string author;
    string publisher;
    Genre genre;
    int publicationYear;
    int available = 0;
    bool availabilityStatus = (available > 0);

public:

    // Setter and Getter methods for each member variable
    void setISBN(const string num);

    void setTitle(const string n);

    void setAuthor(const string n);

    void setGenre(const int n);

    void setPublisher(const string n);

    void setAvailableNum(int n);

    string getISBN() const;

    string getTitle() const;

    string getAuthor() const;

    string getPublisher() const;

    int getGenre() const;

    int getAvailableNum() const;
};

class Member{
private:
    string userID;
    string userName;
    string password;
    Role role;
    Book *checkedOut;
    int fines;

public:
    Member();
    Member(string ID, string user, string pass);
    void login();
    void manageAccount();
    void setRole(Role n);
    void setname (string name);
    void setID(string id);
    void setpassword(string pass);
    string getname()const;
    string getID() const;
    string getpassword() const;
    int getrole()const;


    void searchBooks(string input);
};

class Loan :public Member
{
public:
    time_t loandate;
    time_t duedate;
    struct tm * duetime = localtime(&duedate);
    struct tm * loantime = localtime(&loandate);
    int days;
public:
    Loan();

    void set_loan();

    bool is_overdue();

};

class Student : public Member{
private:

public:
    void requestLoan();

    void returnBook();

};
#endif //LIBRARYMANAGEMENT_H

class Librarian : public Member{
private:

public:
    Librarian();

    Librarian(string id, string user, string pass);

    void addBook();

    void removeBook();

    void updateBook();

    void viewMembers();

    void addMember();

    void removeMember();

    void processLoanRequest();

    void generateReports();
};