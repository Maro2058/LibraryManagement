

#include "LibraryManagement.h"


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
            return "Other";
    }
}
//-----------------------------------------------------

//start of Book class functions

// Setter and Getter methods for each member variable
void Book::setISBN(const string num){ ISBN = num; }
void Book::setTitle(const string n){title = n; }
void Book::setAuthor(const string n){author = n;}
void Book::setGenre(const int n){genre = static_cast<Genre>(n); }
void Book::setPublisher(const string n){publisher = n;}
void Book::setAvailableNum(int n){available = n;}
string Book:: getISBN() const { return ISBN; }
string Book:: getTitle() const { return title; }
string Book::getAuthor() const { return author; }
string Book::getPublisher()const{ return publisher; }
int Book::getGenre() const { return genre; }
int Book::getAvailableNum() const { return available; }
//end of Book class functions

//---------------------------------------------

//start of Member class functions

void Member::setRole(Role n){role = (n);}
void Member::setname (string name) {userName = name;}
void Member::setID(string id){userID = id;}
void Member::setpassword(string pass){password = pass;}
string Member::getname()const{return userName;}
string Member::getID() const {return userID;}
string Member::getpassword() const {return password;}
Role Member::getrole()const{return role;}

Member::Member(){userID = "22-101097"; userName = "Amro Edris"; password = "amro123";}
Member::Member(string ID, string user, string pass) : userID(ID), userName(user), password(pass) {}
void Member::login(){
    string tempID;
    string tempPass;
    cout << " Enter User ID: ";
    getline(cin,  tempID);
    cout << endl << "Enter Password: " << endl;
    getline(cin,  tempPass);

    vector<Member> members;

    readFile("Members.txt", members);

    for (size_t i = 0; i <members.size(); i++) {
        if (members[i].getID() == tempID && members[i].getpassword() != tempPass) {
            cout << "Incorrect Password. " <<endl;

        } else if(members[i].getID() == tempID && members[i].getpassword() == tempPass) {
            this->setname(members[i].getname());
            this->setRole(members[i].getrole());
            this->setID(members[i].getID());
            this->setpassword(members[i].getpassword());
        }
    }

}

vector<Member> Member::readFile(string fileName, vector<Member> &members) {
    ifstream file(fileName);  // Open file for reading

    if (!file.is_open()) {
        cout << "Unable to open file." << endl;
        return members;
    }

    int num;
    string line;
    Member tempmember;

    while (getline(file, line)) {
        num = stoi(line);
        tempmember.setRole(static_cast<Role>(num));
        getline(file, line); tempmember.setname(line);
        getline(file, line); tempmember.setID(line);
        getline(file, line); tempmember.setpassword(line);
        members.push_back(tempmember);  // Add Member to vector
    }
    file.close();
    return members;

}

vector<Book> Member:: readFile(string fileName, vector<Book> &books) {
    ifstream file(fileName);  // Open file for reading
    if (!file.is_open()) {
        cout << "Unable to open file." << endl;
        return books;
    }

    string line;
    while (getline(file, line)) {
        int num;
        Book tempBook;
        tempBook.setISBN(line);
        getline(file, line); tempBook.setTitle(line);
        getline(file, line); tempBook.setAuthor(line);
        getline(file, line); tempBook.setGenre(static_cast<Genre>(stoi(line)));
        getline(file, line); tempBook.setPublisher(line);
        getline(file, line); tempBook.setAvailableNum(stoi(line));
        books.push_back(tempBook);  // Add book to vector
    }
    file.close();
    return books;
}

void Member::manageAccount(){
    //change password?
}

void Member::searchBooks(string input) {

    vector<Book> books;
    readFile("Books.txt", books);
    ofstream writeFile("Search_Results.txt");
    for (size_t i = 0; i <books.size(); i++) {
        if (input == books[i].getISBN() || input == books[i].getTitle() || input == books[i].getAuthor() ||
        input == to_string(books[i].getGenre()) || input == books[i].getPublisher()) {
            writeFile << books[i].getISBN() << endl << books[i].getTitle() << endl
            << books[i].getAuthor() << endl << books[i].getGenre() << endl
            << books[i].getPublisher() << endl << books[i].getAvailableNum() << endl;
        }
    }
}
//end of member class functions

//-------------------------------------------

//start of loan Derived class functions

Loan::Loan()
{
    //member id and book
    loandate = time(nullptr);
    duedate = loandate;
}
void Loan::setloanstatus(int a) {loanstatus = a;}

int Loan::getloanstatus() const {return loanstatus;}
void Loan::set_loan()
{
    cout<<"how long will you be having the book for (in days): "<<endl;
    cin>> days;

    duedate = loandate+days *24*60*60;

    //remove book from available book secion
}

bool Loan::is_overdue() {
    time_t now;
    time(&now); // Get current time
    return difftime(now, duedate) > 0; // Check if current time is past the due date
}

//End of Loan Derived class functions

//------------------------------------------

//Start of Student Derived class functions

void Student::  requestLoan(){
    vector<Book> books;// Vector to store books read from file
    vector<Loan> loans;
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
    cout<<"Enter the Book you want to request to Loan: ";
    cin>>choice;
    if(choice>=1 && choice < (books.size()))
    {
        fstream file("Loan.txt", ios :: app);  // Open file for writing (truncating the existing content)
        if (!file.is_open()) {
            cout << "Unable to open file." << endl;
            return;
        }

        Member amr;
        file <<books[choice-1].getISBN() << endl;
        file <<books[choice-1].getTitle() << endl;
        file <<books[choice-1].getAuthor() << endl;
        file << amr.getname()<<endl;
        file << amr.getID()<<endl;
        file << "0" << endl;
        file.close();  // Close the file
    }
}
void Student::returnBook(){
    vector<Loan> loans; // Vector to store books read from file
    Member amr;
    fstream file("Loan.txt", ios::in);  // Open file for reading

    if (!file.is_open()) {
        cout << "Unable to open file." << endl;
        return;
    }

    // Read books from file
    string line;
    while (getline(file, line)) {
        Loan tempLoan;
        tempLoan.setISBN(line);
        getline(file, line); tempLoan.setTitle(line);
        getline(file, line); tempLoan.setAuthor(line);
        getline(file, line); tempLoan.setPublisher(line);
        getline(file, line); tempLoan.setname(line);
        getline(file, line); tempLoan.setID(line);
        getline(file, line); tempLoan.setloanstatus(stoi(line));

        loans.push_back(tempLoan);  // Add book to vector
    }
    file.close();  // Close the file

    // Display available books and prompt user to select a book to remove
    cout << "Books you've taken:" << endl;
    for (size_t i = 0; i < loans.size(); ++i) {
        if((loans[i].getID()).compare(amr.getID()) && loans[i].getloanstatus() == '1')
        cout << i + 1 << ". " << loans[i].getTitle() << " by " << loans[i].getAuthor() << endl;
    }

    int choice;
    cout << "Enter the number of the book you want to return: ";
    cin >> choice;

    if (choice >= 1 && choice <= static_cast<int>(loans.size())) {
            loans.erase(loans.begin() + choice - 1);  // Remove selected book from vector


        // Write remaining books back to file
        file.open("Loans.txt", ios::out | ios::trunc);  // Open file for writing (truncating the existing content)
        if (!file.is_open()) {
            cout << "Unable to open file." << endl;
            return;
        }

        for (const auto& loan : loans) {
            file << loan.getISBN() << '\n';
            file << loan.getTitle() << '\n';
            file << loan.getAuthor() << '\n';
            file << loan.getname() << '\n';
            file << loan.getID() << '\n';
            file << loan.getloanstatus() << '\n';

        }
        file.close();  // Close the file
        cout << "Book removed successfully." << endl;
    } else {
        cout << "Invalid choice." << endl;
    }
}

//End of Student Derived class functions

//------------------------------------------

//Start of Librarian Derived class functions

Librarian::Librarian(){}
Librarian::Librarian(string id, string user, string pass) : Member(id, user, pass) {}

void Librarian::addBook(){ // Adds book to file and returns Book
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

void Librarian::removeBook() {
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

void Librarian::updateBook(){
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
void Librarian::viewMembers(){
    vector<Member> members;
    readFile("Members.txt", members);  // Vector to store books read from file
    // Display available books and prompt user to select a book to remove
    cout << "Members:" << endl;
    for (size_t i = 0; i < members.size(); i++) {
        cout << i + 1 << ". " << members[i].getname() << " || " << members[i].getID() << endl;
    }
}



void Librarian::addMember(){
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
void Librarian::removeMember(){
    vector<Member> members;
    readFile("Members.txt", members);  // Vector to store books read from file

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
        ofstream file("Members.txt");  // Open file for writing (truncating the existing content)
        if (!file.is_open()) {
            cout << "Unable to open file." << endl;
            return;
        }
        for (const auto& member : members) {
            file << (member.getrole()) << '\n';
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
void Librarian ::processLoanRequest(){}
void Librarian::generateReports(){}


//End of Librarian Derived class functions
//-----------------------------------------------