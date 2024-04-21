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
 *
 * Reading from Books:
 *   Currently 3 different versions of the same code
 *   Unify all into 1
 */


/*using namespace std;

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

enum Role
{
    Admin,
    Student
};


string genreToString(Genre genre) {
    switch(genre) {
        case Genre::Fiction: return "Fiction";
        case Genre::NonFiction: return "Non-Fiction";
        case Genre::Mystery: return "Mystery";
        case Genre::Romance: return "Romance";
        case Genre::ScienceFiction: return "Science Fiction";
        case Genre::Biography: return "Biography";
        case Genre::History: return "History";
        case Genre::Poetry: return "Poetry";
        case Genre::Philosophy: return "Philosophy";
        case Genre::Other: return "Other";
        default: return "Unknown";
    }
}

string genreToString(int genre) {
    switch(genre) {
        case Genre::Fiction: return "Fiction";
        case Genre::NonFiction: return "Non-Fiction";
        case Genre::Mystery: return "Mystery";
        case Genre::Romance: return "Romance";
        case Genre::ScienceFiction: return "Science Fiction";
        case Genre::Biography: return "Biography";
        case Genre::History: return "History";
        case Genre::Poetry: return "Poetry";
        case Genre::Philosophy: return "Philosophy";
        case Genre::Other: return "Other";
        default: return "Unknown";
    }
}

class Book{
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
    void setISBN(const string num){ ISBN = num; }
    void setTitle(const string n){ title = n; }
    void setAuthor(const string n){ author = n; }
    void setGenre(const int n){ genre = static_cast<Genre>(n); }
    void setPublisher(const string n){ publisher = n; }
    void setAvailableNum(int n){ available = n; }

    string getISBN() const { return ISBN; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getPublisher()const{ return publisher; }
    int getGenre() const { return genre; }
    int getAvailableNum() const { return available; }


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
    Member(){}
    Member(string ID, string user, string pass) : userID(ID), userName(user), password(pass) {}
    void login(){
        cout << " Enter User ID" << endl;
        cout << "Enter Password" << endl;
    }
    void manageAccount(){
        //change password?
    }
    void setRole(Role n){role = static_cast<Role>(n);}
    void setname (string name) {userName = name;}
    void setID(string id){userID = id;}
    void setpassword(string pass){password = pass;}
    string getname()const{return userName;}
    string getID() const {return userID;}
    string getpassword() const {return password;}
    int getrole()const{return role;}


    void searchBooks(string input){

        Book tempBook;
        string tempString;
        int tempInt;

        ifstream readFile("Books.txt");
        ofstream writeFile("Search_Results.txt");
        if (readFile.is_open()){
            for (size_t i = 1; i <= 6 && !readFile.eof(); i++){
                cout << i << endl;
                switch(i){
                    case 1:
                        getline(readFile, tempString); tempBook.setISBN(tempString);
                        break;
                    case 2:
                        getline(readFile, tempString); tempBook.setTitle(tempString);
                        break;
                    case 3:
                        getline(readFile, tempString); tempBook.setAuthor(tempString);
                        break;
                    case 4:
                        getline(readFile, tempString); tempBook.setGenre(stoi(tempString));
                        cout << "Here:";
                        break;
                    case 5:
                        getline(readFile, tempString); tempBook.setPublisher(tempString);
                        break;
                    case 6:
                        getline(readFile, tempString); tempBook.setAvailableNum(stoi(tempString));
                        i = 0;
                        if (input == tempBook.getISBN() || input == tempBook.getTitle() || input == tempBook.getAuthor() ||
                            input == to_string(tempBook.getGenre()) || input == tempBook.getPublisher()){
                                writeFile << tempBook.getISBN() << endl << tempBook.getTitle() << endl
                                << tempBook.getAuthor() << endl << tempBook.getGenre() << endl
                                << tempBook.getPublisher() << endl << tempBook.getAvailableNum() << endl;
                        }
                        break;
                }
            }
        } else {
            cout << "File failed to open";
        }


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
    Librarian(string id, string user, string pass) : Member(id, user, pass) {}

    void addBook(){ // Adds book to file and returns Book
        string Input;
        Book tempBook;
        fstream file("Books.txt", ios :: app);

        if (file.is_open()){

            cout << "Enter the Books Info:\n ISBN: ";
            cin>>Input;
            while(Input.length() != 13 || !all_of(Input.begin(), Input.end(), ::isdigit) ) {
                cout << "Error! Make sure the ISBN is 13 digits" << endl;
                cout << "Enter the Books Info:\n ISBN: ";
                cin.clear(); // Clear error flags
                cin.ignore(numeric_limits<streamsize>::max(),'\n'); // reads and discards all characters up to the newline character ('\n')
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
            getline(cin, Input);
            tempBook.setPublisher(Input);
            file << Input << '\n';
// Enter Genre
            cout << "Select Genre:\n";
            cout << "1. Fiction\n";
            cout << "2. NonFiction\n";
            cout << "3. Mystery\n";
            cout << "4. Romance\n";
            cout << "5. ScienceFiction\n";
            cout << "6. Biography\n";
            cout << "7. History\n";
            cout << "8. Poetry\n";
            cout << "9. Philosophy\n";
            cout << "10. Other\n";
            int choice;
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear input buffer

            switch(choice) {
                case 1: tempBook.setGenre(Genre::Fiction); break;
                case 2: tempBook.setGenre(Genre::NonFiction); break;
                case 3: tempBook.setGenre(Genre::Mystery); break;
                case 4: tempBook.setGenre(Genre::Romance); break;
                case 5: tempBook.setGenre(Genre::ScienceFiction); break;
                case 6: tempBook.setGenre(Genre::Biography); break;
                case 7: tempBook.setGenre(Genre::History); break;
                case 8: tempBook.setGenre(Genre::Poetry); break;
                case 9: tempBook.setGenre(Genre::Philosophy); break;
                case 10: tempBook.setGenre(Genre::Other); break;
                default:
                    cout << "Invalid choice. Setting genre to Other." << endl;
                    tempBook.setGenre(Genre::Other);
                    break;
            }
            // Write to file
            file << static_cast<int>(tempBook.getGenre()) << '\n';  // Write enum value as integer


            int num;
            cout << "Enter The Number of Books Available: "<<endl;
            cin>>num;
            while(num < 1)
            {
                cout<<"Invalid Amount! Please try again.";
                cin>>num;
            }
            tempBook.setAvailableNum(num);
            file << num << '\n';
            file.close();

        } else{
            cout << "File Failed to Open\n Press any Number to continue"<<endl;
            cin >> Input;
            cin.clear();
        }
    }

   void removeBook() {
        string ISBN;
        vector<Book> books;  // Vector to store books read from file
        fstream file("Books.txt", ios::in);  // Open file for reading

        if (!file.is_open()) {
            cout << "Unable to open file." << endl;
            return;
        }

        // Read books from file
        string line;
        while (getline(file, line)) {
            Book tempBook;
            tempBook.setISBN(line);
            getline(file, line); tempBook.setTitle(line);
            getline(file, line); tempBook.setAuthor(line);
            getline(file, line); tempBook.setPublisher(line);
            int genreValue;
            file >> genreValue;  // Read genre as integer
            file.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear newline character
            Genre genre = static_cast<Genre>(genreValue);  // Convert integer to Genre enum
            tempBook.setGenre(genre);

            int availableNum;  // Declare variable to store availableNum
            file >> availableNum;  // Read availableNum as integer
            file.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear newline character
            tempBook.setAvailableNum(availableNum);  // Set availableNum for the book

            books.push_back(tempBook);  // Add book to vector
        }
        file.close();  // Close the file

        // Display available books and prompt user to select a book to remove
        cout << "Available Books:" << endl;
        for (size_t i = 0; i < books.size(); ++i) {
            cout << i + 1 << ". " << books[i].getTitle() << " by " << books[i].getAuthor() << endl;
        }

        int choice;
        cout << "Enter the number of the book to remove: ";
        cin >> choice;

        if (choice >= 1 && choice <= static_cast<int>(books.size())) {
            if(books[choice-1].getAvailableNum() == 1) {
                books.erase(books.begin() + choice - 1);  // Remove selected book from vector
            }
            else
            {
                int num = books[choice-1].getAvailableNum();
                books[choice-1].setAvailableNum(--(num));
            }

            // Write remaining books back to file
            file.open("Books.txt", ios::out | ios::trunc);  // Open file for writing (truncating the existing content)
            if (!file.is_open()) {
                cout << "Unable to open file." << endl;
                return;
            }

            for (const auto& book : books) {
                file << book.getISBN() << '\n';
                file << book.getTitle() << '\n';
                file << book.getAuthor() << '\n';
                file << book.getPublisher() << '\n';
                file << static_cast<int>(book.getGenre()) << '\n';
                file << book.getAvailableNum() << '\n';
            }
            file.close();  // Close the file
            cout << "Book removed successfully." << endl;
        } else {
            cout << "Invalid choice." << endl;
        }
    }

    void updateBook(){
        vector<Book> books;  // Vector to store books read from file
        fstream file("Books.txt", ios::in);  // Open file for reading

        if (!file.is_open()) {
            cout << "Unable to open file." << endl;
            return;
        }

        // Read books from file
        string line;
        int genreValue;
        int avalnum;

        while (getline(file, line)) {
            Book tempBook;
            tempBook.setISBN(line);
            getline(file, line); tempBook.setTitle(line);
            getline(file, line); tempBook.setAuthor(line);
            getline(file, line); tempBook.setPublisher(line);
            int genreValue;
            file >> genreValue;  // Read genre as integer
            file.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear newline character
            Genre genre = static_cast<Genre>(genreValue);  // Convert integer to Genre enum
            tempBook.setGenre(genre);

            int availableNum;  // Declare variable to store availableNum
            file >> availableNum;  // Read availableNum as integer
            file.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear newline character
            tempBook.setAvailableNum(availableNum);  // Set availableNum for the book

            books.push_back(tempBook);  // Add book to vector
        }

        file.close();// Close the file
        cout << "Available Books:" << endl;
        for (size_t i = 0; i < books.size(); ++i) {
            cout << i + 1 << ". " << books[i].getTitle() << " by " << books[i].getAuthor() << endl;
        }

        int choice;
        cout << "Enter the number of the book to modify: ";
        cin >> choice;

        if (choice >= 1 && choice <= static_cast<int>(books.size())) {
            int choice2;
            cout<<"1.ISBN: "<<books[choice-1].getISBN()<<endl;
            cout<<"2.Title Name: "<<books[choice-1].getTitle()<<endl;
            cout<<"3.Author's Name: "<<books[choice-1].getAuthor()<<endl;
            cout<<"4.Publisher's Name: "<<books[choice-1].getPublisher()<<endl;
            cout<<"5.Genre: "<<genreToString(books[choice-1].getGenre())<<endl;
            cout<<"6.Available no.: "<<books[choice-1].getAvailableNum()<<endl;
            cout<<"What do you want to modify?"<<endl;
            cin>>choice2;

            string tISBN;
            string ttitle;
            string tauthor;
            string tpublish;
            int gnre;
            int tavb;
            int choice3;

            switch(choice2)
            {
                case 1:
                    cout<<"Please enter the new ISBN: "<<endl;
                    cin.ignore();
                    getline(cin, tISBN);
                    while(tISBN.length()!= 13)
                    {
                        cout<<"Invalid ISBN, Please try to enter a 13 digit ISBN"<<endl;
                        cin.ignore();
                        getline(cin, tISBN);
                    }
                    books[choice-1].setISBN(tISBN);
                    break;
                case 2:
                    cout<<"Please enter the new title: "<<endl;
                    cin.ignore();
                    getline(cin, ttitle);
                    books[choice-1].setTitle(ttitle);
                    break;
                case 3:
                    cout<<"Please enter the new author name: "<<endl;
                    cin.ignore();
                    getline(cin, tauthor);
                    books[choice-1].setAuthor(tauthor);
                    break;
                case 4:
                    cout<<"Please enter the new Publisher's name: "<<endl;
                    cin.ignore();
                    getline(cin, tpublish);
                    books[choice-1].setPublisher(tpublish);
                    break;
                case 5:
                    cout<<"Please choose the new genre: "<<endl;
                    cout << "1. Fiction\n";
                    cout << "2. NonFiction\n";
                    cout << "3. Mystery\n";
                    cout << "4. Romance\n";
                    cout << "5. ScienceFiction\n";
                    cout << "6. Biography\n";
                    cout << "7. History\n";
                    cout << "8. Poetry\n";
                    cout << "9. Philosophy\n";
                    cout << "10. Other\n";
                    cin >> choice3;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear input buffer

                    switch(choice3) {
                        case 1: books[choice-1].setGenre(Genre::Fiction); break;
                        case 2: books[choice-1].setGenre(Genre::NonFiction); break;
                        case 3: books[choice-1].setGenre(Genre::Mystery); break;
                        case 4: books[choice-1].setGenre(Genre::Romance); break;
                        case 5: books[choice-1].setGenre(Genre::ScienceFiction); break;
                        case 6: books[choice-1].setGenre(Genre::Biography); break;
                        case 7: books[choice-1].setGenre(Genre::History); break;
                        case 8: books[choice-1].setGenre(Genre::Poetry); break;
                        case 9: books[choice-1].setGenre(Genre::Philosophy); break;
                        case 10: books[choice-1].setGenre(Genre::Other); break;
                        default:
                            cout << "Invalid choice. Setting genre to Other." << endl;
                            books[choice-1].setGenre(Genre::Other);
                            break;
                    }
                    break;
                case 6:
                    cout<<"Please enter the new available number: "<<endl;
                    cin.ignore();
                    cin>>tavb;
                    while(tavb < 0)
                    {
                        cout<<"Invalid Number! Try Again: ";
                        cin>>tavb;
                    }
                    if(tavb == 0)
                    {
                        books.erase(books.begin() + choice - 1);
                    }
                    else {
                        books[choice - 1].setAvailableNum(tavb);
                    }
                    break;

                default:
                    cout<<"Invalid choice, Try Again."<<endl;
                    break;
            }

            // Write remaining books back to file
            file.open("Books.txt", ios::out | ios::trunc);  // Open file for writing (truncating the existing content)
            if (!file.is_open()) {
                cout << "Unable to open file." << endl;
                return;
            }

            for (const auto &book: books) {
                file << book.getISBN() << '\n';
                file << book.getTitle() << '\n';
                file << book.getAuthor() << '\n';
                file << book.getPublisher() << '\n';
                file << book.getGenre() << '\n';
                file << book.getAvailableNum() << '\n';

            }
            file.close();  // Close the file
            cout << "Book modified successfully." << endl;
        }else{
            cout<<"Invalid choice";
        }
    }
    void viewMembers(){
        vector<Member> members;  // Vector to store books read from file
        ifstream file("Members.txt");  // Open file for reading

        if (!file.is_open()) {
            cout << "Unable to open file." << endl;
            return;
        }

        // Read books from file
        string line;
        while (getline(file, line)) {
            Member tempmember;
            int r = stoi(line);
            tempmember.setRole(static_cast<Role>(r));
            getline(file, line); tempmember.setname(line);
            getline(file, line); tempmember.setID(line);
            getline(file, line); tempmember.setpassword(line);

            members.push_back(tempmember);  // Add book to vector
        }
        file.close();  // Close the file

        // Display available books and prompt user to select a book to remove
        cout << "Members:" << endl;
        for (size_t i = 0; i < members.size(); i++) {
            cout << i + 1 << ". " << members[i].getname() << " || " << members[i].getID() << endl;
        }
    }
    void addMember(){
        string Input;
        Member tempMember;
        fstream file("Members.txt", ios :: app);

        if (file.is_open()){
            int userchoice;
            cout << "Enter the Member Info:\n Is the member:\n1. Librarian\n2. Student \n";
            cin>>userchoice;
            while(userchoice < 1 || userchoice > 2)
            {
                cout<<"Invalid choice! Pick again."<<endl;
                cin>>userchoice;
            }
            file << userchoice << '\n';
            cin.ignore();
            tempMember.setRole(static_cast<Role>(userchoice));


            cout << "Enter the Member's Name: ";
            getline(cin, Input);
            tempMember.setname(Input);
            file << Input << '\n';

            cout << "Enter the Member's ID: ";
            getline(cin, Input);
            //searches if ID exists somewhere
            tempMember.setID(Input);
            file << Input << '\n';

            cout << "Enter the Member's Password: ";
            getline(cin, Input);
            tempMember.setpassword(Input);
            file << Input << '\n';

            file.close();

        } else{
            cout << "File Failed to Open\n Press any Number to continue"<<endl;
            cin >> Input;
            cin.clear();
        }
    }
    void removeMember(){
        vector<Member> members;  // Vector to store books read from file
        fstream file("Members.txt", ios::in);  // Open file for reading

        if (!file.is_open()) {
            cout << "Unable to open file." << endl;
            return;
        }

        // Read books from file
        string line;
        while (getline(file, line)) {
            Member tempmember;
            int r = stoi(line);
            tempmember.setRole(static_cast<Role>(r));
            getline(file, line); tempmember.setname(line);
            getline(file, line); tempmember.setID(line);
            getline(file, line); tempmember.setpassword(line);

            members.push_back(tempmember);  // Add book to vector
        }
        file.close();  // Close the file

        // Display available books and prompt user to select a book to remove
        cout << "Members:" << endl;
        for (size_t i = 0; i < members.size(); ++i) {
            cout << i + 1 << ". " << members[i].getname() << " || " << members[i].getID() << endl;
        }

        int choice;
        cout << "Enter the number of the Member to remove: ";
        cin >> choice;

        if (choice >= 1 && choice <= static_cast<int>(members.size())) {
            members.erase(members.begin() + choice - 1);  // Remove selected book from vector


            // Write remaining books back to file
            file.open("Members.txt", ios::out | ios::trunc);  // Open file for writing (truncating the existing content)
            if (!file.is_open()) {
                cout << "Unable to open file." << endl;
                return;
            }

            for (const auto& member : members) {
                file << static_cast<int>(member.getrole()) << '\n';
                file << member.getname() << '\n';
                file << member.getID() << '\n';
                file << member.getpassword() << '\n';
            }
            file.close();  // Close the file
            cout << "Member removed successfully." << endl;
        } else {
            cout << "Invalid choice." << endl;
        }
    }
    void processLoanRequest(){

    }
    void generateReports(){

    }
};*/

int main()
{

    Librarian morad;
    morad.viewMembers();
    morad.addMember();
    morad.removeMember();


    return 0;
}