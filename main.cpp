#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <algorithm> // for std::all_of
#include <cctype>    // for std::isdigit


using namespace std;

class Book{
private:
    string ISBN; // Easier to use as String, otherwise it would long int, which is incompatible with some functions
    string title;
    string author;
    string publisher;
    enum genre {Art = 1, Biology, BusinessAndEconomics, Chemistry, ComputerScience, Education, Engineering,
        HealthAndNutrition, Language, Mathematics, Music, Physics, Psychology};
    int publicationYear;
    bool availabilityStatus;
    int available;

public:
    void setISBN(string num){
        ISBN = num;
    }
    string getISBN(){
        return ISBN;
    }
    void setTitle(string n){
        title = n;
    }
    void setAuthor(string n){
        author = n;
    }
    void setPublisher(string n){
        publisher = n;
    }
};

class Member{
private:
    string userID;
    string userName;
    int password;
    Book *checkedOut;
    int fines;

public:
    Member(){}
    Member(string ID, string user, int pass) : userID(ID), userName(user), password(pass) {}
    void login(){
        cout << " Enter User ID" << endl;
        cout << "Enter Password" << endl;
    }
    void manageAccount(){

    }
    void searchBooks(){

    }
};

class Student : public Member{
private:

public:
    void requestLoan(){

    }
    void returnBook(){

    }

};

class Librarian : public Member{
private:

public:
    Librarian(){}
    Librarian(string id, string user, int pass) : Member(id, user, pass) {}

    void addBook(){ // Adds book to file and returns Book
        string anyInput;
        Book tempBook;
        fstream file("Books.txt", ios :: out);

        if (file.is_open()){

            cout << "Enter the Books Info:\n ISBN: ";
            cin >> anyInput;
            while(anyInput.length() != 13 || !all_of(anyInput.begin(), anyInput.end(), ::isdigit) ) {
                cout << "Error! Make sure the ISBN is 13 digits" << endl;
                cout << "Enter the Books Info:\n ISBN: ";
                cin.clear(); // Clear error flags
                cin >> anyInput;
            }
            tempBook.setISBN(anyInput);
            file << anyInput;

            cout << "Enter the book's title: ";
            cin >> anyInput;
            tempBook.setTitle(anyInput);
            file << anyInput;

            cout << "Enter the Author's name: ";
            cin >> anyInput;
            tempBook.setAuthor(anyInput);
            file << anyInput;

            cout << "Enter the Publisher: ";
            cin >> anyInput;
            tempBook.setPublisher(anyInput);
            file << anyInput;

        } else{
            cout << "File Failed to Open\n Press any Number to continue"<<endl;
            cin >> anyInput;
            cin.clear();
        }
    }
    void removeBook(Book& book){

    }
    void updateBook(){

    }
    void viewMembers(){

    }
    void addMember(){
        Member tempMember();
    }
    void removeMember(Member member){

    }
    void processLoanRequest(){

    }
    void generateReports(){

    }
};

class Loan{
private:
    int memberID;
    int bookISBN;
    time_t borrowDate;
    time_t dueDate;

public:
    void setBorrowDate(){
        borrowDate = time(nullptr);
        if(borrowDate == -1){ //Error Handling, in case time() returns error value

        }
    }
};

int main()
{
    Librarian librarian;
    librarian.addBook();
    cout<<"Hello World";

    return 0;
}
