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
        //change password?
    }
    void searchBooks(){

    }
};

class Student : public Member{
private:

public:
    void requestLoan(){
        Loan loan;

        loan.set_loan();
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
        fstream file("Books.txt", ios :: app);

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

class Loan :public Member
{
public:
    time_t loandate;
    time_t duedate;
    struct tm * duetime = localtime(&duedate);
    struct tm * loantime = localtime(&loandate);
    int days;
public:
    Loan()
    {
        //member id and book
        loandate = time(nullptr);
        duedate = loandate;
    }

    void set_loan()
    {
        cout<<"how long will you be having the book for (in days): "<<endl;
        cin>> days;

        duedate = loandate+days *24*60*60;

        //remove book from available book secion
    }

    bool is_overdue() {
        time_t now;
        time(&now); // Get current time
        return difftime(now, duedate) > 0; // Check if current time is past the due date
    }
};

int main()
{
    Librarian librarian;
    librarian.addBook();
    cout<<"Hello World";

    return 0;
}

