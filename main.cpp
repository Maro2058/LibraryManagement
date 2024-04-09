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

public:
    void setISBN(string num){
        ISBN = num;
    }
    string getISBN(){
        return ISBN;
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
    Librarian(string id, string user, int pass) : Member(id, user, pass) {}

    void addBook(){ // Adds book to file and returns Book
        string num;
        Book tempBook;
        fstream file("C:\\Users\\Morad Elshorbagy\\Desktop\\University\\LibraryMangementSystem\\Books.txt", ios::in);

        if (file.is_open()){
            cout << "Enter the Books Info:\n ISBN:";
            cin >> num;

            while(num.length()!=13 || !all_of(num.begin(), num.end(), ::isdigit) ) {
                cout << "Error! Make sure the ISBN is 13 digits" << endl;
                cout << "Enter the Books Info:\n ISBN:";
                cin.clear(); // Clear error flags
                cin >> num;
            }
            tempBook.setISBN(num);
            file >> num;

        } else{
            cout << "File Failed to Open\n Press any Number to continue"<<endl;
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
    Librarian librarian(std::string(), std::string(), 0);
    librarian.addBook();
    cout<<"Hello World";

    return 0;
}
