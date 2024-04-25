

#ifndef LIBRARYMANAGEMENT_H
#define LIBRARYMANAGEMENT_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <chrono>
#include <ctime>
#include <algorithm> // for std::all_of
#include <cctype>    // for std::isdigit
#include <vector>

using namespace std;

class GenreList {
protected:
    vector<string> genres = {
            "Fiction",
            "NonFiction",
            "ScienceFiction",
            "Business",
            "Philosophy",
            "History",
            "Geography",
            "Programming",
            "physics",
            "Calculus",
            "Other"
    };

    string genre;
public:

    void displayGenres() const;

    void addGenre(const string& genre);

    void removeGenre(const string& genre);

    bool isValidGenre(const string& genre) const;

    vector<string> TheGenres()const;

    void setGenre(string n);

    string getGenre() const;

};


enum Role {
    Admin,
    student
};





class MyString {
private:
    string str;

public:
    // Default constructor
    MyString();

    // Parameterized constructor
    MyString(const string& s);

    // Copy constructor
    MyString(const MyString& other);

    // Destructor
    ~MyString();

    // Display method
    void display() const;

    // Concatenation operator
    MyString operator+(const MyString& other) const;

    // Assignment operator
    MyString& operator=(const MyString& other);

    // Comparison operator
    bool operator==(const MyString& other) const;
};


class Book : public GenreList {
protected:
    string ISBN; // Easier to use as String, otherwise it would long int, which is incompatible with some functions
    string title;
    string author;
    string publisher;
    string genre;
    int publicationYear;
    int available = 0;
    bool availabilityStatus = (available > 0);

public:

    // Setter and Getter methods for each member variable
    void setISBN(const string num);

    void setTitle(const string n);

    void setAuthor(const string n);

    void setPublisher(const string n);

    void setAvailableNum(int n);

    void deserialize(string);

    string getISBN() const;

    string getTitle() const;

    string getAuthor() const;

    string getPublisher() const;

    string serialize() const;

    int getAvailableNum() const;

    // Prototypes for the Unary Functions Overloading
    Book& operator++();
    Book operator++(int);
    Book& operator--();
    Book operator--(int);

};


class Member{
protected:
    string userID;
    string userName;
    string password;
    Role role;
    Book *checkedOut;
    int fines;

public:
    Member() = default;
    Member(const Member& other);
    Member(std::string ID, std::string user, std::string pass);
    ~Member();
    Member* login();
    void manageAccount();
    void setRole(Role n);
    void setname (string name);
    void setID(string id);
    void setpassword(string pass);
    string getname()const;
    string getID() const;
    string getpassword() const;
    Role getrole()const;
    string serialize() const;
    bool is_There(string n);
    void deserialize(string);

    vector<Book> searchBooks(string input);
};



class Student : public Member, public MyString{
private:

public:
    Student();
    Student(const string& ID, const string& user, const string& pass);
    Student(const Member& other);
    ~Student();
    void requestLoan();
    void returnBook();
};

class Librarian : public Member{
private:

public:
    Librarian();
    Librarian(const string& ID, const string& user, const string& pass);
    Librarian(const Member& other);
    ~Librarian();

    void addBook();
    void removeBook();
    void updateBook();
    void viewMembers();
    void addMember();
    void removeMember();
    void processLoanRequest();
    void generateReports();

};
class Loan :public Member, public Book, public MyString
{
protected:
    time_t loandate;
    time_t duedate;
    struct tm * duetime = localtime(&duedate);
    struct tm * loantime = localtime(&loandate);
    int days;
    char loanstatus;
public:
    Loan();
    void set_loan(int days);
    void setloanstatus(int a);
    int getloanstatus () const;
    void setloandate(time_t a);
    void setduedate(time_t a);
    time_t getloandate()const;
    time_t getduedate()const;
    string serialize() const;
    void deserialize(string);
    string formatdate (time_t) const;
    time_t stringToTime(string& dateStr);
    bool is_overdue();
};

#endif //LIBRARYMANAGEMENT_H