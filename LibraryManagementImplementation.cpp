

#include "LibraryManagement.h"

// global vectors to use in code
vector<Book> books;
vector<Member> members;
vector<Loan> loans;


// Writes File, works with Members/Books/Loans
template<typename T>
void writeFile(string fileName,vector<T> data) {
    ofstream file(fileName, ios::out | ios::trunc); // Open file for writing (truncating the existing content)
    if (!file.is_open()) {
        cout << "Unable to open file." << endl;
        return;
    }
    for (const auto& item : data) {
        file << item.serialize() << '\n';
    }
    file.close();
}
//Reads Files, works with Members/Books/Loans
template<typename T>
vector<T> readFile(const string& fileName, vector<T>& data) {
    string line;
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "Unable to open file (READ)." << endl;
        return data;
    }
    while (getline(file, line)) {
        T item;
        item.deserialize(line);
        data.push_back(item);
    }
    file.close();
    return data;
}

// Prints out all genres to screen
void GenreList::displayGenres() const {
    for (const auto& genre : genres) {
        cout << genre << endl;
    }
}

// Adds Genre to list of genres
void GenreList::addGenre(const string& genre) {
    genres.push_back(genre);
}

//Removes genre
void GenreList::removeGenre(const string& genre) {
    auto it = std::find(genres.begin(), genres.end(), genre);
    if (it != genres.end()) {
        genres.erase(it);
    }
}

//Checks if inputted string is a valid genre
bool GenreList:: isValidGenre(const string& genre) const {
    return find(genres.begin(), genres.end(), genre) != genres.end();
}

//returns list of genre values for a vector
vector<string> GenreList:: getGenres() const { // Made public for access
    return genres;
}

//-----------------------------------------------------

// Default constructor
MyString::MyString() : str("") {}
// Parameterized constructor
MyString::MyString(const std::string& s) : str(s) {}
// Copy constructor
MyString::MyString(const MyString& other) : str(other.str) {}
// Destructor
MyString::~MyString() {}

// Display method
void MyString::display() const {
    std::cout << str;
}

// Concatenation operator
MyString MyString::operator+(const MyString& other) const {
    MyString newString;
    newString.str = str + other.str;
    return newString;
}

// Assignment operator
MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        str = other.str;
    }
    return *this;
}

// Comparison operator
bool MyString::operator==(const MyString& other) const {
    return (str == other.str);
}

// End of MyString class functions
//-----------------------------------------------------
//Start of Book class functions

// Setter and Getter methods for each member variable
void Book::setISBN(const string num){ ISBN = num; }
void Book::setTitle(const string n){title = n; }
void Book::setAuthor(const string n){author = n;}
void Book::setPublisher(const string n){publisher = n;}
void Book::setAvailableNum(int n){available = n;}
void Book::setGenre(const string &n) { genre = n;}
string Book:: getISBN() const { return ISBN; }
string Book:: getTitle() const { return title; }
string Book::getAuthor() const { return author; }
string Book::getPublisher()const{ return publisher; }
string Book::getGenre() const {return genre;}
int Book::getAvailableNum() const { return available; }

// Formats the way Books are stored in files
string Book::serialize() const {
    stringstream ss;
    ss << ISBN << '|'
       << title << '|'
       << author << '|'
       << genre << '|'
       << publisher << '|'
       << available;
    return ss.str();
}
// Extracts book attributes from serialized text
void Book::deserialize(string serializedData) {
    stringstream ss(serializedData);
    getline(ss, ISBN, '|');
    getline(ss, title, '|');
    getline(ss, author, '|');
    getline(ss, genre,'|');
    getline(ss, publisher,'|');

    ss >> available;
}

//Unary function overloading:
// Prefix Increment Operator
Book& Book::operator++() {
    string file = "Books.txt";
    if (available > 0) {
        ++available;
        cout << "A copy of " << title << " has been successfully added to the library" << endl;
    } else {
        cout << "The book doesn't exist." << endl;
    }
    return *this;
}
// Prefix Decrement Operator
Book& Book::operator--() {
    string file = "Books.txt";
    if (available > 0) {
        --available;
        cout << "A copy of " << title << " has been successfully added to the library" << endl;
    } else {
        cout << "The book doesn't exist." << endl;
    }
    return *this;
}
// Postfix Increment Operator
Book Book::operator++(int) {
    Book temp = *this;
    if (available > 0) {
        ++available;
        cout << "A copy of " << title << " has been successfully added to the library" << endl;
    } else {
        cout << "The book doesn't exist." << endl;
    }
    return temp; // Return the saved state
}
// Postfix Decrement Operator
Book Book::operator--(int) {
    Book temp = *this;
    if (available > 0) {
        --available;
        cout << "A copy of " << title << " has been successfully added to the library" << endl;
    } else {
        cout << "The book doesn't exist." << endl;
    }
    return temp; // Return the saved state
}

//end of Book class functions
//---------------------------------------------
//start of Member class functions


// Parameterized constructor
Member::Member(string r, string ID, string user, string pass, double f):fine(f), role(r), userID(ID), userName(user), password(pass) {}
// Copy constructor
Member::Member(const Member& other): fine(other.fine),role(other.role), userID(other.userID), userName(other.userName), password(other.password) {}
// Destructor
Member::~Member() {}

// Setter & Getter Functions
void Member::setRole(string n){role = (n);}
void Member::setname (string name) {userName = name;}
void Member::setID(string id){userID = id;}
void Member::setpassword(string pass){password = pass;}
void Member::setfine(time_t a) {
    double rate = 20;
    time_t now = time(nullptr);
    double difference = difftime(now, a);

    if(difference > 0)
    {
        int daysLate = static_cast<int>(ceil(difference / (60 * 60 * 24)));

        // Calculate the fine
        fine += (daysLate * rate);
    }
    else
        fine = 0;

}

void Member :: setfine(){fine = 0;}
string Member::getname()const{return userName;}
string Member::getID() const {return userID;}
string Member::getpassword() const {return password;}
string Member::getrole()const{return role;}
double Member::getfine() const {return fine;}

// Formats the way Members are stored in files
string Member::serialize() const {
    stringstream ss; // Makes a string stream called ss

    ss << role << '|'
       << userName << '|'
       << userID << '|'
       << password<<'|'
       << fine;
    return ss.str(); // Returns string
}

// Extracts member attributes from serialized text
void Member::deserialize(string serializedData) {
    stringstream ss(serializedData); //Passes serialized Data to string stream
    string roleStr, name, id, pass;

    //string stream seperates the serialized data into component attributes
    getline(ss, roleStr, '|');
    role = roleStr;
    getline(ss, name,'|');
    userName = name;
    getline(ss, id, '|');
    userID = id;
    getline(ss, pass, '|');
    password = pass;
    ss >> fine;

}

// Login function
Member* Member::login(string tempID, string tempPass) {


    //creates a vector of Member objects to read into
    vector<Member> members;
    readFile("Members.txt", members);

    // Iterate over all members to look for login info
    for (size_t i = 0; i < members.size(); i++) {
        if(members[i].getrole()== "Admin"){
            if (members[i].getID() == tempID && members[i].getpassword() != tempPass) {
                cout << "Incorrect Password "<<endl;
            } else if (members[i].getID() == tempID && members[i].getpassword() == tempPass) {
            // Correct user ID and password, return pointer to Member object
            Member* loggedInMember = new Librarian(members[i]); // copy constructor is called
            cout<<"Logged in Successfully"<<endl;
            return loggedInMember;
            }
        }
        if(members[i].getrole()== "Student"){
            if (members[i].getID() == tempID && members[i].getpassword() != tempPass) {
                cout << "Incorrect Password "<<endl;
            } else if (members[i].getID() == tempID && members[i].getpassword() == tempPass) {
                // Correct user ID and password, return pointer to Member object
                Member* loggedInMember = new Student(members[i]); // copy constructor is called
                cout<<"Logged in Successfully"<<endl;
                return loggedInMember;
            }
        }
    }
    cout << "No Member Found"<< endl;
    // User ID or password incorrect, return nullptr
    return nullptr;
}

int Member :: loginGui(string userId, string userPass) {
    Member* temp = Member :: login(userId, userPass);
    if (typeid(*temp) == typeid(Librarian)) {return 2;}
    if (typeid(*temp) == typeid(Student)) {return 1;}
    return 0;

}
// Searches Saved Books for Inputted String
void Member::searchBooks() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Please Enter the term you want to search for"<<endl;
    string input;
    getline(cin, input);
    books.clear();
    readFile("Books.txt", books);

    bool flag = false;
    vector<Book> searchResults;
    for (const auto& book : books) {
        if (input == book.getISBN() || input == book.getTitle() || input == book.getAuthor() ||
        input == book.getGenre() || input == book.getPublisher()) {
            flag = true;
            searchResults.push_back(book);
        }
    }
    if (flag == false) {
        cout << "No books found.";
        return;
    }
    for (const auto & result : searchResults) {
        cout << result.getTitle() << "  by: " << result.getAuthor() << endl;
    }
}
// Prints all Book Title and Authors for reading
void Member::viewBooks() {
    books.clear();
    readFile("Books.txt", books);

    for(int i = 0; i < books.size(); i++)
    {
        cout<<i+1 <<". "<<books[i].getTitle()<<" by "<<books[i].getAuthor()<<endl;
    }
}

// Allows members to change their username or password
void Member::manageAccount(){
    int inputInt;
    string inputString;
    members.clear();
    readFile("Members.txt", members);

    cout << "1. Change Username" << endl << "2. Change Password" << endl;
    cin >> inputInt;
    if (inputInt == 1) {
        cout << "Enter New Username: ";
        cin >> inputString;
    } else if (inputInt == 2) {
        cout << "Enter New Password: ";
        cin >> inputString;
    } else {
        cout << "Invalid Input";
        return;
    }

    // Looks for Logged in user, and applies changes
    for (auto & member : members) {
        if (member.getID() == this->getID()) {
            cout << "User Found"<<endl;
            if (inputInt == 1) {
                member.setname(inputString);
            } else if (inputInt == 2) {
                member.setpassword(inputString);
            }
        }
    }
    writeFile("Members.txt", members);
}

// Virtual Functions
void Member::addBook() {
    // Virtual Function.
    //Doesn't do Anything
}

void Member::removeBook() {
    // Virtual Function.
    //Doesn't do Anything
}

void Member::updateBook() {
    // Virtual Function.
    //Doesn't do Anything
}

void Member::viewMembers() {
    // Virtual Function.
    //Doesn't do Anything
}

void Member::addMember() {
    // Virtual Function.
    //Doesn't do Anything
}

void Member::removeMember() {
    // Virtual Function.
    //Doesn't do Anything
}

void Member::processLoanRequest() {
    // Virtual Function.
    //Doesn't do Anything
}

void Member ::requestLoan() {
    // Virtual Function.
    //Doesn't do Anything
}
void Member::returnBook() {
    // Virtual Function.
    //Doesn't do Anything
}

void Member::generateReports() {
    // Virtual Function.
    //Doesn't do Anything
}
void Member::manageMembers() {
    // Virtual Function.
    //Doesn't do Anything
}
void Member::manageBooks() {
    // Virtual Function.
    //Doesn't do Anything
}

void Member::UserReport() {}

//end of member class functions
//-------------------------------------------
//Start of Student Derived class functions

Student::Student() : Member() {}
// Parameterized constructor
Student::Student(const string& role, const string& ID, const string& user, const string& pass, double f): Member(role, ID, user, pass, f) {}
// Copy constructor
Student::Student(const Member& other) : Member(other) {}
// Destructor
Student::~Student() {}


void Student :: requestLoan(){

    Member::viewBooks();
    loans.clear();
    readFile("Loan.txt",loans);
    int choice;

    cout<<"Enter the Book you want to request to Loan: "<<endl;
    cin>>choice;

    if(choice>=1 && choice <= (books.size()) && (books[choice-1].getAvailableNum())> 0)
    {
        Loan tempLoan;
        int days;
        cout<<"How long will you take the book for? (in days): "<<endl;
        cin >> days;
        tempLoan.setduedate(days);
        tempLoan.setISBN(books[choice-1].getISBN());
        tempLoan.setTitle(books[choice-1].getTitle());
        tempLoan.setAuthor(books[choice-1].getAuthor());
        tempLoan.setname(this->getname());
        tempLoan.setID(this->getID());
        tempLoan.setloanstatus(0);

        loans.push_back(tempLoan);
        writeFile("Loan.txt",loans);
    }
}

void Student :: calculateFine(time_t now) {

}

void Student::returnBook(){
    // Read books from file
    loans.clear();
    readFile("Loan.txt",loans);
    vector<size_t> filteredIndices;

// Populate filteredIndices with indices of loans that meet the criteria
    for (size_t i = 0; i < loans.size(); ++i) {
        if ((loans[i].getID() == this->getID()) && loans[i].getloanstatus() == 1) {
            filteredIndices.push_back(i);
        }
    }

// Display available books and prompt user to select a book to return
    cout << "Books you've taken:" << endl;
    for (size_t i = 0; i < filteredIndices.size(); ++i) {
        cout << i + 1 << ". " << loans[filteredIndices[i]].getTitle() << " by " << loans[filteredIndices[i]].getAuthor() << " due: " << loans[filteredIndices[i]].formatdate(loans[filteredIndices[i]].getduedate()) << endl;
    }

    int choice;
    cout << "Enter the number of the book you want to return: ";
    cin >> choice;
    books.clear();
    readFile("Books.txt", books);
    members.clear();
    readFile("Members.txt",members);


// Adjust the user's choice to match the correct index in the loans vector
    if (choice >= 1 && choice <= static_cast<int>(filteredIndices.size())) {
        size_t selectedLoanIndex = filteredIndices[choice - 1];

       for(int i = 0; i < books.size(); i++)
       {
           if(books[i].getISBN() == loans[selectedLoanIndex].getISBN())
           {
               books[i]++;
           }
       }

        for(int i = 0; i< members.size();i++)
        {
            if(this->getID()==members[i].getID())
            {
                members[i].setfine(loans[selectedLoanIndex].getduedate());
            }
        }
        loans.erase(loans.begin() + selectedLoanIndex);

        // Write remaining books back to file
        // Write remaining loans back to file
        writeFile("Loan.txt", loans);
        writeFile("Books.txt",books);
        writeFile("Members.txt", members);
        cout << "Book removed successfully." << endl;
    } else {
        cout << "Invalid choice." << endl;
    }
}

void Student::UserReport() {
    loans.clear();
    readFile("Loan.txt", loans);
    int i = 1;
    double totalfines = 0;
    cout<<"User Name: "<<this->getname()<<endl;
    cout<<"User ID: "<<this->getID()<<endl;
    cout<<"Books Loaned:"<<endl;
    for(const auto &loan: loans)
    {
        if(loan.getID() == this->getID())
        {
            cout<<i<<". "<<loan.getTitle()<<"|| Due Date: "<< loan.formatdate(loan.getduedate())<<endl;
            totalfines += loan.getfine();
            ++i;
        }
    }
    cout<<"User fine: "<<this->getfine()<<"$"<<endl;
}

//End of Student Derived class functions
//------------------------------------------
//Start of Librarian Derived class functions

Librarian::Librarian() : Member() {cout << "librarian created" ;}
// Parameterized constructor
Librarian::Librarian(const string& role, const string& ID, const string& user, const string& pass, double f): Member(role, ID, user, pass, f) {cout << "librarian created" ;}
// Copy constructor
Librarian::Librarian(const Member& other) : Member(other) {cout << "librarian created" ;}
// Destructor
Librarian::~Librarian() {}

/* Writes to Book file in the following order:
Book ISBN | Book Title | Book Author | Book Genre | Book Publisher | Number Availble of Book*/
void Librarian::addBook(){ // Adds book to file and returns Book
    books.clear();
    readFile("Books.txt", books);
    string Input;
    Book tempBook;

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
    cin.ignore(); //discards

    cout << "Enter the Book's title: ";
    getline(cin, Input);
    tempBook.setTitle(Input);

    cout << "Enter the Author's name: ";
    getline(cin, Input);
    tempBook.setAuthor(Input);

    GenreList genreList;
// Enter Genre
    cout << "Select Genre:\n";
    int index = 1;
    for (const auto& genre : genreList.getGenres()) {
    cout << index << ". " << genre << '\n';
    ++index;
}
    int choice;
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear input buffer
    tempBook.setGenre(genreList.getGenres()[choice-1]);
    // Write to file

    cout << "Enter the Publisher: ";
    getline(cin, Input);
    tempBook.setPublisher(Input);
    int num;
    cout << "Enter The Number of Books Available: "<<endl;
    cin>>num;
    while(cin.fail() || num < 0)
    {
        cout<<"Invalid Amount! Please try again.";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n'); // reads and discards all characters up to the newline character ('\n')
        cin>>num;
    }
    tempBook.setAvailableNum(num);

    books.push_back(tempBook); // Add the new Book to the vector
    writeFile("Books.txt", books); // Write the entire vector back to the file
}

// Removes Book from file
void Librarian::removeBook() {
    books.clear();
    readFile("Books.txt", books);

    // Display available books and prompt user to select a book to remove
    cout << "Available Books:" << endl;
    for (size_t i = 0; i < books.size(); ++i) {
        cout << i + 1 << ". " << books[i].getTitle() << " by " << books[i].getAuthor() << endl;
    }
    int choice;
    cout << "Enter the number of the book to remove: ";
    cin >> choice;

    if (choice >= 1 && choice <= static_cast<int>(books.size())) {
        books.erase(books.begin() + choice - 1);
        // Write remaining books back to file
        writeFile("Books.txt", books);
        cout << "Book removed successfully." << endl;
    } else {
        cout << "Invalid choice." << endl;
    }
}

// Changes the stored infromation of the Books
void Librarian::updateBook(){
    books.clear();
    readFile("Books.txt", books);

    //choose which book to modify
    cout << "Available Books:" << endl;
    for (size_t i = 0; i < books.size(); ++i) {
        cout << i + 1 << ". " << books[i].getTitle() << " by " << books[i].getAuthor() << endl;
    }
    int choice;
    cout << "Enter the number of the book to modify: ";
    cin >> choice;

    // Choosing what to modify in the book
    if (choice >= 1 && choice <= static_cast<int>(books.size())) {
        int choice2;
        cout<<"1.ISBN: "<<books[choice-1].getISBN()<<endl;
        cout<<"2.Title Name: "<<books[choice-1].getTitle()<<endl;
        cout<<"3.Author's Name: "<<books[choice-1].getAuthor()<<endl;
        cout<<"4.Publisher's Name: "<<books[choice-1].getPublisher()<<endl;
        cout<<"5.Genre: "<<books[choice-1].getGenre()<<endl;
        cout<<"6.Available no.: "<<books[choice-1].getAvailableNum()<<endl;
        cout<<"What do you want to modify?"<<endl;
        cin>>choice2;

        // More Variables than we'll ever need.
        // If it ain't broke don't fix it.
        string tISBN;
        string ttitle;
        string tauthor;
        string tpublish;
        int gnre;
        int tavb;
        int choice3;
        int i = 0;
        int index = 1;
        GenreList genreList;

        // Performing the modifications
        switch(choice2)
        {
            case 1:
                cout<<"Please enter the new ISBN: "<<endl;
                cin>>tISBN;
            while(tISBN.length() != 13 || !all_of(tISBN.begin(), tISBN.end(), ::isdigit) ) {
                cout << "Error! Make sure the ISBN is 13 digits" << endl;
                cout << "Enter the Books Info:\n ISBN: ";
                cin.clear(); // Clear error flags
                cin.ignore(numeric_limits<streamsize>::max(),'\n'); // reads and discards all characters up to the newline character ('\n')
                cin >> tISBN;
            }
                while(i!=books.size()){
                    if(books[i].getISBN()==tISBN)
                    {
                        cout<<"ISBN Already Registered! Do you want to add"<<endl;
                        getline(cin, tISBN);
                        i = -1;
                    }
                    i++;
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
                cout << "Select Genre:\n";
                for (const auto& genre : genreList.getGenres()) {
                    cout << index << ". " << genre << '\n';
                    ++index;
                }
                cin >> choice3;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear input buffer

                if (choice >= 1 && choice <= genreList.getGenres().size()) {
                    books[choice-1].setGenre(genreList.getGenres()[choice3-1]);
                } else {
                    cout << "Invalid choice. Setting genre to Other." << endl;
                    books[choice-1].setGenre("Other");
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
                books[choice - 1].setAvailableNum(tavb);
                break;
            default:
                cout<<"Invalid choice, Try Again."<<endl;
                break;
        }

        // Write remaining books back to file
        writeFile("Books.txt", books);
        cout << "Book modified successfully." << endl;
    }else{
        cout<<"Invalid choice";
    }
}

// Display all Members
void Librarian::viewMembers(){
    members.clear();
    readFile("Members.txt", members);  

    cout << "Members:" << endl;
    for (size_t i = 0; i < members.size(); i++) {
        cout << i + 1 << ". " << members[i].getname() << " || " << members[i].getID() <<endl;
    }
}

/*Writes to Member file in the following order:
Member Role | Member Name | Member ID | Member Password */
void Librarian::addMember() {
    members.clear();
    readFile("Members.txt", members);
    string Input;
    Member tempMember;

    // Gets User Info
    int userchoice;
    cout << "Enter the Member Info:\n Is the member:\n1. Librarian\n2. Student \n";
    cin >> userchoice;
    while (userchoice < 1 || userchoice > 2 || cin.fail()) {
        cout << "Invalid choice! Pick again." << endl;
        cin >> userchoice;
    }

    if (userchoice == 1) {
        tempMember.setRole("Admin");
    } else if (userchoice == 2) {
        tempMember.setRole("Student");
    }
    cin.ignore();

    cout << "Enter the Member's Name: ";
    getline(cin, Input);
    tempMember.setname(Input);

    bool flag = true;

    while(flag == 1) { // Makes sure the Id isn't already taken
        flag = false;
        cout << "Enter the Member's ID: ";
        getline(cin, Input);
        //searches if ID exists somewhere
        for (const auto& member : members) {
            if (Input == member.getID()) {
                cout << "This ID Already Exists" << endl;
                flag = true;
            }
        }
    }
    tempMember.setID(Input);

    cout << "Enter the Member's Password: ";

    cin >> Input;
    tempMember.setpassword(Input);
    tempMember.setfine();

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    members.push_back(tempMember);


    // Write the entire vector back to the file
    writeFile("Members.txt", members);
}

// Removes a chosen member
void Librarian :: removeMember() {
    members.clear();
    readFile("Members.txt", members);  // Vector to store members read from file
    // Display available members
    cout << "Members:" << endl;
    for (size_t i = 0; i < members.size(); ++i) {
        cout << i + 1 << ". " << members[i].getname() << " || " << members[i].getID() << endl;
    }

    // Erases Member from vector
    int choice;
    cout << "Enter the number of the Member to remove: ";
    cin >> choice;
    if (choice >= 1 && choice <= static_cast<int>(members.size())) {
        members.erase(members.begin() + choice - 1);
        writeFile("Members.txt", members); // Writes new vector back to file
        cout << "Member removed successfully." << endl;
    } else {
        cout << "Invalid choice." << endl;
    }
}

// Allows the Librarian to Accept Loan Requests
void Librarian ::processLoanRequest(){
    loans.clear();
    readFile("Loan.txt", loans);
    vector<size_t> filteredIndices; // To store Unprocessed Loan Requests
    time_t now;
    time(&now); // Get current time


    // Populate filteredIndices with indices of loans that meet the criteria
    for (size_t i = 0; i < loans.size(); ++i) {
        if (loans[i].getloanstatus() == 0) {
            filteredIndices.push_back(i);
        }
    }

    if (filteredIndices.empty()) {
        cout << "No Incoming Loan Requests" << endl;
        return;
    }

    // Display available books and prompt librarian to approve a book
    cout << "Loan Requests:" << endl;
    for (size_t i = 0; i < filteredIndices.size(); ++i) {
        cout << i + 1 << ". " << loans[filteredIndices[i]].getTitle() << " by " << loans[filteredIndices[i]].getAuthor() << " due: " << loans[filteredIndices[i]].formatdate(loans[filteredIndices[i]].getloandate()) << endl;
    }

    int choice;
    cout << "Enter the number of the book you want to approve: ";
    cin >> choice;

    size_t selectedLoanIndex = filteredIndices[choice - 1];
    books.clear();
    readFile("Books.txt", books);

    if (choice >= 1 && choice <= static_cast<int>(loans.size())) {
        for(int i = 0; i < books.size();i++)
        {
            if(books[i].getISBN() == loans[selectedLoanIndex].getISBN())
            {
                books[i]--;
            }
        }
        loans[selectedLoanIndex].setloanstatus(1);

        double days = difftime((loans[selectedLoanIndex].getduedate()),(loans[selectedLoanIndex].getloandate()));
        loans[selectedLoanIndex].setLoanDate();
        loans[selectedLoanIndex].setduedate(days);

        writeFile("Books.txt", books);
        writeFile("Loan.txt",loans);
        cout << "Book request has been approved." << endl;
    } else {
        cout << "Invalid choice." << endl;
    }
}



void Librarian::generateReports(){
    // Read loans data from file
    loans.clear();
    readFile("Loan.txt", loans);

bool flag = false;
    for(const auto &loan : loans)
    {
        if(loan.getloanstatus() == 1) {
            cout<<"User ID: "<< loan.getID()<<" Book Loaned: "<< loan.getTitle()<<" due date: "<<loan.formatdate(loan.getduedate())<<endl;
            flag = true;
        }
    }
if (flag == false) {
    cout << "Nothing to report" << endl;
}
}


// Sub Menu to call Member functions
void Librarian::manageMembers() {
    int option = 0;
    cout << "1: View Members" << endl;
    cout << "2: Add Members" << endl;
    cout << "3: Remove Members" << endl;
    cout << "4: Back" << endl;
    cin >> option;
    if (option == 1) {
        viewMembers();
    } else if (option == 2) {
        addMember();
    } else if (option == 3) {
        removeMember();
    } else if (option == 4) {
        return;
    } else {
        cout << "Invalid Input";
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
}

// Sub menu to call Book Functions
void Librarian::manageBooks() {
    int option = 0;
    while (option != 5) {
        cout << "1: Add Book" << endl;
        cout << "2: Remove Book" << endl;
        cout << "3: Update Book" << endl;
        cout << "4: Search Books " << endl;
        cout << "5: View Books " << endl;
        cout << "6: Back" << endl;

        cin >> option;
        if (option == 1) {
            addBook();
        } else if (option == 2) {
            removeBook();
        } else if (option == 3) {
            updateBook();
        } else if (option == 4) {
            searchBooks();
        }else if (option == 5) {
            viewBooks();
        }else if (option == 6) {
            return;
        }else {
            cout << "Invalid Input" << endl;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
}

//End of Librarian Derived class functions
//-----------------------------------------------
//start of loan Derived class functions

Loan:: Loan() {
        //member id and book
        loandate = time(nullptr);
        duedate = loandate;
    }

// Setter and Getter Functions
void Loan::setloanstatus(int a) {loanstatus = a;}
int Loan::getloanstatus() const {return loanstatus;}
void Loan :: setduedate(int a){
    loandate = time(nullptr);
    duedate = loandate + a*24*60*60;
    duetime = localtime(&duedate);
    loantime = localtime(&loandate);
}

void Loan ::setduedate(double a) {
    loandate = time(nullptr);
    duedate = loandate + a;
    duetime = localtime(&duedate);
    loantime = localtime(&loandate);
}

time_t Loan :: getduedate()const {return duedate;}
void Loan::setLoanDate() {
    loandate = time(nullptr);
    loantime = localtime(&loandate);
}
time_t Loan :: getloandate()const {return loandate;}

// Formats the way Loan are stored in files
string Loan::serialize() const {
    stringstream ss;
    ss << ISBN << '|'
       << title << '|'
       << author << '|'
       << userName << '|'
       << userID << '|'
       << formatdate(loandate) <<'|'
       << formatdate(duedate)<<'|'
       << loanstatus;

    return ss.str();
}

// Extracts loan attributes from serialized text
void Loan::deserialize(string serializedData) {
    stringstream ss(serializedData);
    getline(ss, ISBN,'|');
    getline(ss, title, '|');
    getline(ss, author, '|');
    getline(ss, userName, '|');
    getline(ss, userID,'|');
    string loandateStr;
    getline(ss, loandateStr, '|');
    loandate = stringToTime(loandateStr);
    string duedateStr;
    getline(ss, duedateStr, '|');
    duedate = stringToTime(duedateStr);
    int status;
    ss >> status;
    loanstatus = status;
}

// Writes date in dd/mm/yyyy format
string Loan ::formatdate(time_t a) const{
    string s;
    time_t temp = a;
    tm * date = localtime(&temp);
    s = to_string(date->tm_mday) + "/" + to_string(date->tm_mon + 1) + "/" + to_string(date->tm_year + 1900);
    return s;
}

// Converts input from string format to time format (Used for deserialization)
time_t Loan::stringToTime(string& dateStr) {
    struct tm timeStruct = {};
    stringstream ss(dateStr); // Reads the string to stream
    // Converts the string to tm automatically using streams.
    ss >> timeStruct.tm_mday;
    ss.ignore(); // Skip the '/'
    ss >> timeStruct.tm_mon;
    ss.ignore(); // Skip the '/'
    ss >> timeStruct.tm_year;
    timeStruct.tm_mon--; // Adjust month (0-based)
    timeStruct.tm_year -= 1900; // Adjust year (years since 1900)
    return mktime(&timeStruct);
}

// Checks if Loan is overdue
bool Loan::is_overdue() {
    time_t now;
    time(&now); // Get current time
    return difftime(now, duedate) > 0; // Check if current time is past the due date
}

//End of Loan Derived class functions
//-----------------------------------------------
