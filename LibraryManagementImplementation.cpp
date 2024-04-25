#include "LibraryManagement.h"


vector<Book> books;
vector<Member> members;
vector<Loan> loans;

void GenreList::displayGenres() const {
    for (const auto& genre : genres) {
        cout << genre << endl;
    }
}


void GenreList::addGenre(const string& genre) {
    genres.push_back(genre);
}

void GenreList::removeGenre(const string& genre) {
    auto it = std::find(genres.begin(), genres.end(), genre);
    if (it != genres.end()) {
        genres.erase(it);
    }
}

bool GenreList:: isValidGenre(const string& genre) const {
    return find(genres.begin(), genres.end(), genre) != genres.end();
}

vector<string> GenreList:: getGenres() const { // Made public for access
    return genres;
}


//-----------------------------------------------------
// This function is redundant.
//-----------------------------------------------------

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



template<typename T>
void writeFile(string fileName,vector<T>& data) {
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

template<typename T>
vector<T> readFile(const string& fileName, vector<T>& data) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "Unable to open file (READ)." << endl;
        return data;
    }
    string line;
    while (getline(file, line)) {
        T item;
        item.deserialize(line);
        data.push_back(item);
    }
    file.close();
    return data;
}



//start of Book class functions

// Setter and Getter methods for each member variable
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
void Book::deserialize(string serializedData) {
    stringstream ss(serializedData);
    getline(ss, ISBN, '|');
    getline(ss, title, '|');
    getline(ss, author, '|');
    getline(ss, genre,'|');
    getline(ss, publisher,'|');

    ss >> available;

}


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
Member::Member(std::string ID, std::string user, std::string pass):userID(ID), userName(user), password(pass) {}
// Copy constructor
Member::Member(const Member& other): userID(other.userID), userName(other.userName), password(other.password) {}
// Destructor
Member::~Member() {}
void Member::setRole(Role n){role = (n);}
void Member::setname (string name) {userName = name;}
void Member::setID(string id){userID = id;}
void Member::setpassword(string pass){password = pass;}
string Member::getname()const{return userName;}
string Member::getID() const {return userID;}
string Member::getpassword() const {return password;}
Role Member::getrole()const{return role;}
string Member::serialize() const {
    stringstream ss;
    ss << role << '|'
       << userName << '|'
       << userID << '|'
       << password;
    return ss.str();
}
void Member::deserialize(string serializedData) {
    stringstream ss(serializedData);
    string roleStr, name, id, pass;
    getline(ss, roleStr, '|');
    istringstream iss(roleStr);
    int num;
    iss >> num;
    role = static_cast<Role>(num); // Convert role string to enum
    getline(ss, name,'|');
    userName = name;
    getline(ss, id, '|');
    userID = id;
    getline(ss, pass, '|');
    password = pass;
}




Member* Member::login() {
    string tempID;
    string tempPass;
    cout << "Enter User ID: ";
    getline(cin, tempID);
    cout << "Enter Password: ";
    getline(cin, tempPass);
    //creates a vector of Member objects to read
    vector<Member> members;

    readFile("Members.txt", members);

    // Iterate over all members
    for (size_t i = 0; i < members.size(); i++) {
        if(members[i].getrole()==0){
            if (members[i].getID() == tempID && members[i].getpassword() == tempPass) {
            // Correct user ID and password, return pointer to Member object
            Member* loggedInMember = new Librarian(members[i]); // copy constructor is called
            cout<<"Logged in successfull"<<endl;
            return loggedInMember;
            }
        }
        if(members[i].getrole()==1){
            if (members[i].getID() == tempID && members[i].getpassword() == tempPass) {
                // Correct user ID and password, return pointer to Member object
                Member* loggedInMember = new Student(members[i]); // copy constructor is called
                cout<<"Logged in successfull"<<endl;
                return loggedInMember;
            }
        }
    }
    // User ID or password incorrect, return nullptr
    return nullptr;
}

void Member::manageAccount(){
    //change password?

}

vector<Book> Member::searchBooks(string input) {
    books.clear();
    readFile("Books.txt", books);
    vector<Book> searchResults;
    for (const auto & book : books) {
        if (input == book.getISBN() || input == book.getTitle() || input == book.getAuthor() ||
        input == book.getGenre() || input == book.getPublisher()) {
            searchResults.push_back(book);
        }
    }
    return searchResults;
}
//end of member class functions

//-------------------------------------------

//Start of Student Derived class functions
Student::Student() : Member() {}
// Parameterized constructor
Student::Student(const std::string& ID, const std::string& user, const std::string& pass): Member(ID, user, pass) {}
// Copy constructor
Student::Student(const Member& other) : Member(other) {}
// Destructor
Student::~Student() {}

void Student :: requestLoan(){
    books.clear();
    readFile("Books.txt", books);

    // Display available books and prompt user to select a book to remove
    cout << "Available Books:" << endl;
    for (size_t i = 0; i < books.size(); ++i) {
        cout << i + 1 << ". " << books[i].getTitle() << " by " << books[i].getAuthor() << endl;
    }

    int choice;
    cout<<"Enter the Book you want to request to Loan: "<<endl;
    cin>>choice;
    if(choice>=1 && choice <= (books.size()))
    {
        Loan temp;
        int days;
        cout<<"How long will you take the book for? (in days): "<<endl;
        cin >> days;
        temp.set_loan(days);

        Member wtv;
        wtv.setname("amr");
        wtv.setID("22-101097");

        readFile("Loan.txt", loans);
        Loan tempLoan;
        tempLoan.setISBN(books[choice-1].getISBN());
        tempLoan.setTitle(books[choice-1].getTitle());
        tempLoan.setAuthor(books[choice-1].getAuthor());
        tempLoan.setname(wtv.getname());
        tempLoan.setID(wtv.getID());
        tempLoan.setloandate(temp.getloandate());
        tempLoan.setduedate(temp.getduedate());
        tempLoan.setloanstatus(0);

        loans.push_back(tempLoan);
        writeFile("Loan.txt",loans);

    }
}
void Student::returnBook(){

    Member amr;
    // Replace Here with New Loan Function

    // Read books from file
    loans.clear();
    readFile("Loan.txt",loans);

    // Display available books and prompt user to select a book to remove
    cout << "Books you've taken:" << endl;
    int count = 1;
    for (size_t i = 0; i < loans.size(); ++i) {
        if((loans[i].getID()==amr.getID()) && loans[i].getloanstatus() == 1)
        cout << count << ". " << loans[i].getTitle() << " by " << loans[i].getAuthor() << " due: "<<loans[i].formatdate(loans[i].getloandate()) << endl;
        count++;
    }

    int choice;
    cout << "Enter the number of the book you want to return: ";
    cin >> choice;
    books.clear();
    readFile("Books.txt", books);

    if (choice >= 1 && choice <= static_cast<int>(loans.size())) {
            for(auto & book : books)
            {
                if(book.getISBN() == loans[choice-1].getISBN())
                {
                    int n = book.getAvailableNum();
                    book.setAvailableNum(++(n));
                }
            }
        loans.erase(loans.begin() + choice - 1);

        // Write remaining books back to file
        writeFile("Books.txt", books);


        // Write remaining books back to file
        writeFile("Loan.txt",loans);
        cout << "Book removed successfully." << endl;
    } else {
        cout << "Invalid choice." << endl;
    }
}

//End of Student Derived class functions

//------------------------------------------

//Start of Librarian Derived class functions

Librarian::Librarian() : Member() {}
// Parameterized constructor
Librarian::Librarian(const std::string& ID, const std::string& user, const std::string& pass): Member(ID, user, pass) {}
// Copy constructor
Librarian::Librarian(const Member& other) : Member(other) {}
// Destructor
Librarian::~Librarian() {}

/* Writes to Book file in the following order:
 * Book ISBN
 * Book Title
 * Book Author
 * Book Publisher
 * Book Genre
 * Number Availble of Book
 */
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
        while(num < 0)
        {
            cout<<"Invalid Amount! Please try again.";
            cin>>num;
        }
        tempBook.setAvailableNum(num);
        books.push_back(tempBook);

    // Add the new member to the vector

    // Write the entire vector back to the file
    writeFile("Books.txt", books);


}

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
            int num = books[choice-1].getAvailableNum();
            if (num > 0)
            books[choice-1].setAvailableNum(--(num));
            else
                books[choice-1].setAvailableNum(0);


        // Write remaining books back to file

        writeFile("Books.txt", books);

        cout << "Book removed successfully." << endl;

    } else {
        cout << "Invalid choice." << endl;
    }
}

void Librarian::updateBook(){
    books.clear();
    readFile("Books.txt", books);

    cout << "Available Books:" << endl;
    for (size_t i = 0; i < books.size(); ++i) {
        cout << i + 1 << ". " << books[i].getTitle() << " by " << books[i].getAuthor() << endl;
    }

    int choice;
    cout << "Enter the number of the book to modify: ";
    cin >> choice;

    // Replace Here, add Options to modify only 1 thing or < n things

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
                    books[choice3-1].setGenre(genreList.getGenres()[choice3]);
                } else {
                    cout << "Invalid choice. Setting genre to Other." << endl;
                    books[choice3-1].setGenre("Other");
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear input buffer

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
void Librarian::viewMembers(){
    members.clear();
    readFile("Members.txt", members);  
    // Display available books and prompt user to select a book to remove
    cout << "Members:" << endl;
    for (size_t i = 0; i < members.size(); i++) {
        cout << i + 1 << ". " << members[i].getname() << " || " << members[i].getID() <<endl;
    }
}

/*Writes to Member file in the following order:
 * Member Role
 * Member Name
 * Member ID
 * Member Password
 */
void Librarian::addMember() {
    string Input;
    Member tempMember;
    members.clear();
    readFile("Members.txt", members);
    int userchoice;
    cout << "Enter the Member Info:\n Is the member:\n1. Librarian\n2. Student \n";
    cin >> userchoice;
    while (userchoice < 1 || userchoice > 2) {
        cout << "Invalid choice! Pick again." << endl;
        cin >> userchoice;
    }
    tempMember.setRole(static_cast<Role>(userchoice));

    cout << "Enter the Member's Name: " << endl;
    cin.ignore();
    getline(cin, Input);
    tempMember.setname(Input);

    cout << "Enter the Member's ID: ";
    getline(cin, Input);
    int i = 0;
    while(i!=members.size()){
        if(members[i].getID()==Input)
        {
            cout<<"User Already Registered! Try a different username"<<endl;
            getline(cin, Input);
            i = -1;
        }
        i++;
    }
    tempMember.setID(Input);

    cout << "Enter the Member's Password: ";
    getline(cin, Input);
    tempMember.setpassword(Input);


    // Add the new member to the vector
    members.push_back(tempMember);

    // Write the entire vector back to the file
    writeFile("Members.txt", members);
}

void Librarian::removeMember(){
    members.clear();
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

        writeFile("Members.txt", members);
        cout << "Member removed successfully." << endl;
    } else {
        cout << "Invalid choice." << endl;
    }
}
void Librarian ::processLoanRequest(){
    Member amr;
    loans.clear();
    readFile("Loan.txt", loans);


    // Display available books and prompt user to select a book to remove
    cout << "Books that were requested for loan" << endl;
    int count = 1;
    for (size_t i = 0; i < loans.size(); ++i) {
        if(loans[i].getloanstatus() == 0) {
            cout << count << ". " << loans[i].getTitle() << " by " << loans[i].getAuthor() << " Student ID: "
                 << loans[i].getID() << " till: " << loans[i].formatdate(loans[i].getduedate()) << endl;
            count++;
        }
    }

    int choice;
    cout << "Enter the number of the book you want to approve: ";
    cin >> choice;
    books.clear();
    readFile("Books.txt", books);

    if (choice >= 1 && choice <= static_cast<int>(loans.size())) {
        for(int i = 0; i < books.size();i++)
        {
            if(books[i].getISBN() == loans[choice-1].getISBN())
            {
                int n = books[i].getAvailableNum();
                books[i].setAvailableNum(--(n));
            }
        }
        loans[choice-1].setloanstatus(1);



            writeFile("Books.txt", books);

        writeFile("Loan.txt",loans);
        cout << "Book request has been approved." << endl;
    } else {
        cout << "Invalid choice." << endl;
    }

}
void Librarian::generateReports(){}


//End of Librarian Derived class functions

//-----------------------------------------------

//start of loan Derived class functions

Loan::Loan()
{
    //member id and book
    loandate = time(nullptr);
    duedate = loandate;
}
void Loan::setloanstatus(int a) {loanstatus = a;}

int Loan::getloanstatus() const {return loanstatus;}
void Loan::set_loan(int days)
{
    duedate = loandate+days *24*60*60;
    duetime = localtime(&duedate);
    loantime = localtime(&loandate);
}

time_t Loan :: getloandate()const
{
    return loandate;
}
time_t Loan :: getduedate()const
{
    return duedate;
}

string Loan::serialize() const {
    stringstream ss;
    ss << ISBN << '|'
       << title << '|'
       << author << '|'
       << userName << '|'
       << userID << '|'
       << formatdate(duedate)<<'|'
       << formatdate(loandate)<<'|'
       << loanstatus;

    return ss.str();
}

void Loan::deserialize(string serializedData) {
    stringstream ss(serializedData);
    getline(ss, ISBN);
    getline(ss, title);
    getline(ss, author);
    getline(ss, userName);
    getline(ss, userID);
    string loandateStr;
    getline(ss, loandateStr);
    loandate = stringToTime(loandateStr);
    string duedateStr;
    getline(ss, duedateStr);
    duedate = stringToTime(duedateStr);
    int status;
    ss >> status;
    loanstatus = static_cast<char>(status);
    ss.ignore(); // Ignore the newline character
}



void Loan ::setduedate(time_t a) {
    duedate = a;
    duetime = localtime(&duedate);
}

void Loan::setloandate(time_t a) {
    loandate = a;
    loantime = localtime(&loandate);
}

string Loan ::formatdate(time_t a) const{
    string s;
    time_t temp = a;
    struct tm * date = localtime(&temp);
    s = to_string(date->tm_mday) + "/" + to_string(date->tm_mon + 1) + "/" + to_string(date->tm_year + 1900);
    return s;
}

time_t Loan::stringToTime(string& dateStr) {
    struct tm timeStruct = {};
    stringstream ss(dateStr);
    ss >> timeStruct.tm_mday;
    ss.ignore(); // Skip the '/'
    ss >> timeStruct.tm_mon;
    ss.ignore(); // Skip the '/'
    ss >> timeStruct.tm_year;
    timeStruct.tm_mon--; // Adjust month (0-based)
    timeStruct.tm_year -= 1900; // Adjust year (years since 1900)
    return mktime(&timeStruct);
}

bool Loan::is_overdue() {
    time_t now;
    time(&now); // Get current time
    return difftime(now, duedate) > 0; // Check if current time is past the due date
}


//End of Loan Derived class functions

//-----------------------------------------------


void initializeVectors() {
    readFile("Books.txt", books);
    readFile("Members.txt", members);
    readFile("Loans.txt", loans);
}

