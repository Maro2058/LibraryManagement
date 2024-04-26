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
Member* theuser = nullptr;
// Parameterized constructor
Member::Member(string r, string ID, string user, string pass):role(r), userID(ID), userName(user), password(pass) {}
// Copy constructor
Member::Member(const Member& other):role(other.role), userID(other.userID), userName(other.userName), password(other.password) {}
// Destructor
Member::~Member() {}

// Setter & Getter Functions
void Member::setRole(string n){role = (n);}
void Member::setname (string name) {userName = name;}
void Member::setID(string id){userID = id;}
void Member::setpassword(string pass){password = pass;}
string Member::getname()const{return userName;}
string Member::getID() const {return userID;}
string Member::getpassword() const {return password;}
string Member::getrole()const{return role;}

// Formats the way Objects are stored in files
string Member::serialize() const {
    stringstream ss; // Makes a string stream called ss

    ss << role << '|'
       << userName << '|'
       << userID << '|'
       << password;
    return ss.str(); // Returns string
}

// Extracts attributes from serialized text
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
}

// Login function
Member* Member::login() {
    string tempID;
    string tempPass;
    cout << "Enter User ID: ";
    getline(cin, tempID);
    cout << "Enter Password: ";
    getline(cin, tempPass);

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
    for (auto& member : members) {
        if (member.getID() == this->getID()) {
            cout << "User Found";
            if (inputInt == 1) {
                member.setname(inputString);
            } else if (inputInt == 2) {
                setpassword(inputString);
            }
        }
    }
    writeFile("Members.txt", members);
}

// Searches Saved Books for Inputted String
void Member::searchBooks() {
    cout << "Please Enter the term you want to search for"<<endl;
    string input;
    getline(cin, input);
    books.clear();
    readFile("Books.txt", books);

    vector<Book> searchResults;
    for (const auto & book : books) {
        if (input == book.getISBN() || input == book.getTitle() || input == book.getAuthor() ||
        input == book.getGenre() || input == book.getPublisher()) {
            searchResults.push_back(book);
        }
    }
    for (const auto & result : searchResults) {
        cout << result.getTitle() << "  by: " << result.getAuthor() << endl;
    }
}
//end of member class functions

//-------------------------------------------

//Start of Student Derived class functions
Student::Student() : Member() {}
// Parameterized constructor
Student::Student(const string& role, const string& ID, const string& user, const string& pass): Member(role, ID, user, pass) {}
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
        tempLoan.setname(theuser->getname());
        tempLoan.setID(theuser->getID());
        tempLoan.setloanstatus(0);

        loans.push_back(tempLoan);
        writeFile("Loan.txt",loans);

    }
}
void Student::returnBook(){

    // Read books from file
    loans.clear();
    readFile("Loan.txt",loans);
    vector<size_t> filteredIndices;

// Populate filteredIndices with indices of loans that meet the criteria
    for (size_t i = 0; i < loans.size(); ++i) {
        if ((loans[i].getID() == theuser->getID()) && loans[i].getloanstatus() == 1) {
            filteredIndices.push_back(i);
        }
    }

// Display available books and prompt user to select a book to return
    cout << "Books you've taken:" << endl;
    for (size_t i = 0; i < filteredIndices.size(); ++i) {
        cout << i + 1 << ". " << loans[filteredIndices[i]].getTitle() << " by " << loans[filteredIndices[i]].getAuthor() << " due: " << loans[filteredIndices[i]].formatdate(loans[filteredIndices[i]].getloandate()) << endl;
    }

    int choice;
    cout << "Enter the number of the book you want to return: ";
    cin >> choice;
    books.clear();
    readFile("Books.txt", books);
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

        loans.erase(loans.begin() + selectedLoanIndex);

        // Write remaining books back to file
        // Write remaining loans back to file
        writeFile("Loan.txt", loans);
        writeFile("Books.txt",books);
        cout << "Book removed successfully." << endl;
    } else {
        cout << "Invalid choice." << endl;
    }
}

//End of Student Derived class functions

//------------------------------------------

//Start of Librarian Derived class functions

Librarian::Librarian() : Member() {cout << "librarian created" ;}
// Parameterized constructor
Librarian::Librarian(const string& role, const string& ID, const string& user, const string& pass): Member(role, ID, user, pass) {cout << "librarian created" ;}
// Copy constructor
Librarian::Librarian(const Member& other) : Member(other) {cout << "librarian created" ;}
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
        while(cin.fail() || num < 0)
        {
            cout<<"Invalid Amount! Please try again.";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n'); // reads and discards all characters up to the newline character ('\n')
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
        books.erase(books.begin() + choice - 1);


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
    members.clear();
    readFile("Members.txt", members);
    string Input;
    Member tempMember;

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

    while(flag == 1) {
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
    getline(cin, Input);
    tempMember.setpassword(Input);

    members.push_back(tempMember);


    // Write the entire vector back to the file
    writeFile("Members.txt", members);
}

void Librarian :: removeMember() {
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
    loans.clear();
    readFile("Loan.txt", loans);

    vector<size_t> filteredIndices;

// Populate filteredIndices with indices of loans that meet the criteria
    for (size_t i = 0; i < loans.size(); ++i) {
        if (loans[i].getloanstatus() == 0) {
            filteredIndices.push_back(i);
        }
    }

// Display available books and prompt user to select a book to return
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

            writeFile("Books.txt", books);

        writeFile("Loan.txt",loans);
        cout << "Book request has been approved." << endl;
    } else {
        cout << "Invalid choice." << endl;
    }

}
void Librarian::generateReports(){
    /*
    Loan stats for each genre
    The lowest loaned genres
    Stats by term or month
    Top Borrowers
    */

}

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

void Member::manageBooks() {
    // Virtual Function.
    //Doesn't do Anything
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

void Member::manageMembers() {
    // Virtual Function.
    //Doesn't do Anything
}


//End of Librarian Derived class functions

//-----------------------------------------------

//start of loan Derived class functions

Loan:: Loan() {
        //member id and book
        loandate = time(nullptr);
        duedate = loandate;
    }

void Loan::setloanstatus(int a) {loanstatus = a;}

int Loan::getloanstatus() const {return loanstatus;}
/*
void Loan::set_loan(int days)
{
    duedate = loandate+ days *24*60*60;
    duetime = localtime(&duedate);
    loantime = localtime(&loandate);
}
*/
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
       << formatdate(loandate) <<'|'
       << formatdate(duedate)<<'|'
       << loanstatus;

    return ss.str();
}

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
    loanstatus =status;
    // Ignore the newline character
}



void Loan ::setduedate(int a) {
    loandate = time(nullptr);
    duedate = loandate + a *24*60*60;
    duetime = localtime(&duedate);
    loantime = localtime(&loandate);
}

/*
void Loan::setloandate(time_t a) {
    loandate = a;
    loantime = localtime(&loandate);
}
*/
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

