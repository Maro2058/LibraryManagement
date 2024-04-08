#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>

using namespace std;

class Book{
private:
    int ISBN;
    string title;
    string author;
    string publisher;
    enum genre {Art = 1, Biology, BusinessAndEconomics, Chemistry, ComputerScience, Education, Engineering,
        HealthAndNutrition, Language, Mathematics, Music, Physics, Psychology};
    int publicationYear;
    bool availabilityStatus;

public:
    void setISBN(int num){
        ISBN = num;
    }
    int getISBN(){
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
    Book addBook(){ // Adds book to file and returns Book
        int num;
        int anyInput;
        Book tempBook;
        fstream file("output.txt", ios::in);

        if (file.is_open()){
            cout << "Enter the Books Info:\n ISBN:";
            cin >> num;
            string temp  = reinterpret_cast<const char*>(num);

            while(temp.length() != 13){
                cout << "Error! Make sure the ISBN is 13 digits" << endl;
                cout << "Enter the Books Info:\n ISBN:";
                cin >> num;
                temp  = reinterpret_cast<const char*>(num);
            }
            tempBook.setISBN(num);


        } else{
            cout << "File Failed to Open\n Press any Number to continue"<<endl;
            cin >> anyInput;
        }

    }
    void removeBook(Book& book){

    }
    void updateBook(){

    }
    void viewMembers(){

    }
    void addMember(){
        Member* memberRef = new Member;
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
