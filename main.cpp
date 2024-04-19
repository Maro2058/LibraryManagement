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

    void setGenre( ){
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
    void searchBooks(string input){

        if (input == "-1"){
            cout << "This Input is not allowed" << endl;
        }
        long long int pos = 0;
        string readLine;
        ifstream readFile("Books.txt");
        ofstream writeFile("Search_Results.txt");
        if (readFile.is_open()){
            while(!readFile.eof()) {

                getline(readFile, readLine);
                cout << readLine<< endl;

                if (readLine == "-1") {
                    cout<<"found -1"<<endl;
                    //readFile.seekg(-3, ios_base::cur);
                    pos = readFile.tellg();
                    //readFile.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                if (readLine == input) {
                    cout << endl;
                    readFile.seekg(pos);
                    for (int i = 1; i <= 5; i++){
                        getline(readFile, readLine);
                        writeFile << readLine << endl;
                    }

                }
            }

        } else {
            cout << "File failed to open";
        }


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
        string Input;
        Book tempBook;
        fstream file("Books.txt", ios :: app);
        //Adding stuff to test branch

        if (file.is_open()){

            cout << "Enter the Books Info:\n ISBN: ";
            cin >> Input;
            while(Input.length() != 13 || !all_of(Input.begin(), Input.end(), ::isdigit) ) {
                cout << "Error! Make sure the ISBN is 13 digits" << endl;
                cout << "Enter the Books Info:\n ISBN: ";
                cin.clear(); // Clear error flags
                cin.ignore('\n'); // reads and discards all characters up to the newline character ('\n')
                cin >> Input;
            }
            tempBook.setISBN(Input);
            file << Input << '\n';
            cin.ignore(); //discards

            cout << "Enter the Book's title: ";
            getline(cin, Input);
            tempBook.setTitle(Input);
            file << Input << '\n';

            cout << "Enter the Author's name: ";
            getline(cin, Input);
            tempBook.setAuthor(Input);
            file << Input << '\n';

            cout << "Enter the Publisher: ";
            cin >> Input;
            tempBook.setPublisher(Input);
            file << Input << '\n';

            /*
            cout << "Enter the Genre: ";  // New input for genre
            getline(cin, Input);
            tempBook.setGenre(Input);  // Set genre for tempBook
            file << Input << '\n';      // Write genre to file
            */

            file << "-1" << '\n';

            file.close();

        } else{
            cout << "File Failed to Open\n Press any Number to continue"<<endl;
            cin >> Input;
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
    Member mem;
    mem.searchBooks("Morad");
    cout<<"Hello World";

    return 0;
}

