

#include "LibraryManagment.h"

std::string genreToString(Genre genre) {
    switch (genre) {
        case Genre::Fiction:
            return "Fiction";
        case Genre::NonFiction:
            return "Non-Fiction";
        case Genre::Mystery:
            return "Mystery";
        case Genre::Romance:
            return "Romance";
        case Genre::ScienceFiction:
            return "Science Fiction";
        case Genre::Biography:
            return "Biography";
        case Genre::History:
            return "History";
        case Genre::Poetry:
            return "Poetry";
        case Genre::Philosophy:
            return "Philosophy";
        case Genre::Other:
            return "Other";
        default:
            return "Unknown";
    }
}

std::string genreToString(int genre) {
    switch (genre) {
        case Genre::Fiction:
            return "Fiction";
        case Genre::NonFiction:
            return "Non-Fiction";
        case Genre::Mystery:
            return "Mystery";
        case Genre::Romance:
            return "Romance";
        case Genre::ScienceFiction:
            return "Science Fiction";
        case Genre::Biography:
            return "Biography";
        case Genre::History:
            return "History";
        case Genre::Poetry:
            return "Poetry";
        case Genre::Philosophy:
            return "Philosophy";
        case Genre::Other:
            return "Other";
        default:
            return "Unknown";
    }
}

// Setter and Getter methods for each member variable
void Book::setISBN(const string num){ISBN = num;};
void Book::setTitle(const string n){title = n; };
void Book::setAuthor(const string n){author = n;};
void Book::setGenre(const int n){genre = static_cast<Genre>(n); };
void Book::setPublisher(const string n){publisher = n;};
void Book::setAvailableNum(int n){available = n;};

string Book:: getISBN() const { return ISBN; };
string Book:: getTitle() const { return title; };
string Book::getAuthor() const { return author; };
string Book::getPublisher()const{ return publisher; };
int Book::getGenre() const { return genre; };
int Book::getAvailableNum() const { return available; };

Member::Member(){}
Member::Member(string ID, string user, string pass) : userID(ID), userName(user), password(pass) {}
void Member::login(){
    cout << " Enter User ID" << endl;
    cout << "Enter Password" << endl;
}
void Member::manageAccount(){
    //change password?
}
void Member::setRole(Role n){role = static_cast<Role>(n);}
void Member::setname (string name) {userName = name;}
void Member::setID(string id){userID = id;}
void Member::setpassword(string pass){password = pass;}
string Member::getname()const{return userName;}
string Member::getID() const {return userID;}
string Member::getpassword() const {return password;}
int Member::getrole()const{return role;}


void Member::searchBooks(string input) {

    Book tempBook;
    string tempString;
    int tempInt;

    ifstream readFile("Books.txt");
    ofstream writeFile("Search_Results.txt");
    if (readFile.is_open()) {
        for (size_t i = 1; i <= 6 && !readFile.eof(); i++) {
            cout << i << endl;
            switch (i) {
                case 1:
                    getline(readFile, tempString);
                    tempBook.setISBN(tempString);
                    break;
                case 2:
                    getline(readFile, tempString);
                    tempBook.setTitle(tempString);
                    break;
                case 3:
                    getline(readFile, tempString);
                    tempBook.setAuthor(tempString);
                    break;
                case 4:
                    getline(readFile, tempString);
                    tempBook.setGenre(stoi(tempString));
                    cout << "Here:";
                    break;
                case 5:
                    getline(readFile, tempString);
                    tempBook.setPublisher(tempString);
                    break;
                case 6:
                    getline(readFile, tempString);
                    tempBook.setAvailableNum(stoi(tempString));
                    i = 0;
                    if (input == tempBook.getISBN() || input == tempBook.getTitle() || input == tempBook.getAuthor() ||
                        input == to_string(tempBook.getGenre()) || input == tempBook.getPublisher()) {
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
};

