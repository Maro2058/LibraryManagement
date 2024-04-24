

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
    student
};



std::string genreToString(Genre genre);

std::string genreToString(int genre);



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

    // Prototypes for the Unary Functions Overloading
    Book& operator++();
    Book operator++(int);
    Book& operator--();
    Book operator--(int);

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
    Member() = default;
    void login();
     void manageAccount();
    void setRole(Role n);
    void setname (string name);
    void setID(string id);
    void setpassword(string pass);
    string getname()const;
    string getID() const;
    string getpassword() const;
    Role getrole()const;
    static vector<Member> readFile(string fileName = "Members.txt", vector<Member> &book);
    static vector<Book> readFile(string fileName = "Books.txt", vector<Book> &book);
    static void writeFile(string fileName, vector<Book> books);
    static void writeFile(string fileName, vector<Member> member);
    vector<Book> searchBooks(string input);
};



class Student : public Member, public MyString{
private:

public:
    void requestLoan();
    void returnBook();
};

class Librarian : public Member{
private:

public:
    Librarian();
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
private:
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
    string formatdate (time_t);
    time_t stringToTime(string& dateStr);
    bool is_overdue();
    static void readFile(string fileName, vector<Loan> &loans);
    static void writeFile(string fileName, vector<Loan> loans);

};

void initializeVectors(vector<Book>& books, vector<Member>& members, vector<Loan>& loans);
#endif //LIBRARYMANAGEMENT_H