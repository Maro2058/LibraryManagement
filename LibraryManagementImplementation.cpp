

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

void updateBooksFile(vector<Book> books) {
    // Open file for writing (assuming the path is correct and accessible)
    ofstream file("Books.txt", ios::out | ios::trunc); // This will clear the existing content
    if (!file.is_open()) {
        cout << "Unable to open file." << endl;
        return;
    }

    // You should ideally have access to the vector of books from your application

    // Write all books back, including the updated availability of this book
    for (const auto& book : books) {
        file << book.getISBN() << '\n'
             << book.getTitle() << '\n'
             << book.getAuthor() << '\n'
             << book.getPublisher() << '\n'
             << book.getGenre() << '\n'
             << book.getAvailableNum() << '\n';
    }

    file.close();  // Close the file after writing
}

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
        getline(file, line); tempBook.setPublisher(line);
        getline(file, line); tempBook.setGenre(static_cast<Genre>(stoi(line)));
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

void Loan ::setduedate(time_t a) {
    duedate = a;
    duetime = localtime(&duedate);
}

void Loan::setloandate(time_t a) {
    loandate = a;
    loantime = localtime(&loandate);
}

string Loan ::formatdate(time_t a) {
    string s;
    struct tm * date = localtime(&a);
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

//------------------------------------------

//Start of Student Derived class functions

void Student ::  requestLoan(){
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
    cout<<"Enter the Book you want to request to Loan: "<<endl;
    cin>>choice;
    if(choice>=1 && choice <= (books.size()))
    {
        Loan temp;
        int days;
        cout<<"How long will you take the book for? (in days): "<<endl;
        cin >> days;
        temp.set_loan(days);

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
        file << temp.formatdate(temp.getloandate()) << endl;
        file << temp.formatdate(temp.getduedate()) << endl;
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
        getline(file, line); tempLoan.setname(line);
        getline(file, line); tempLoan.setID(line);
        getline(file, line); tempLoan.setloandate(tempLoan.stringToTime(line));
        getline(file, line); tempLoan.setduedate(tempLoan.stringToTime(line));
        getline(file, line);
        if(line == "0")
        tempLoan.setloanstatus(0);
        else
            tempLoan.setloanstatus(1);
        loans.push_back(tempLoan);  // Add book to vector
    }
    file.close();  // Close the file

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

    fstream file2("Books.txt", ios::in);  // Open file for reading

    if (!file2.is_open()) {
        cout << "Unable to open file number 1." << endl;
        return;
    }
    // Read books from file
    string line2;
    vector<Book> books;
    while (getline(file2, line2)) {
        Book tempBook;
        tempBook.setISBN(line2);
        getline(file2, line2); tempBook.setTitle(line2);
        getline(file2, line2); tempBook.setAuthor(line2);
        getline(file2, line2); tempBook.setPublisher(line2);
        int genreValue;
        file2 >> genreValue;  // Read genre as integer
        file2.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear newline character
        Genre genre = static_cast<Genre>(genreValue);  // Convert integer to Genre enum
        tempBook.setGenre(genre);

        int availableNum;  // Declare variable to store availableNum
        file2 >> availableNum;  // Read availableNum as integer
        file2.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear newline character
        tempBook.setAvailableNum(availableNum);  // Set availableNum for the book

        books.push_back(tempBook);  // Add book to vector
    }
    file2.close();

    if (choice >= 1 && choice <= static_cast<int>(loans.size())) {
            for(int i = 0; i < books.size();i++)
            {
                if(books[i].getISBN() == loans[choice-1].getISBN())
                {
                    int n = books[i].getAvailableNum();
                    books[i].setAvailableNum(++(n));
                }
            }
        loans.erase(loans.begin() + choice - 1);

        // Write remaining books back to file
        file.open("Books.txt", ios::out | ios::trunc);  // Open file for writing (truncating the existing content)
        if (!file.is_open()) {
            cout << "Unable to open file number 2." << endl;
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


        // Write remaining books back to file
        file.open("Loan.txt", ios::out | ios::trunc);  // Open file for writing (truncating the existing content)
        if (!file.is_open()) {
            cout << "Unable to open file." << endl;
            return;
        }

        for (auto& loan : loans) {
            file << loan.getISBN() << '\n';
            file << loan.getTitle() << '\n';
            file << loan.getAuthor() << '\n';
            file << loan.getname() << '\n';
            file << loan.getID() << '\n';
            file << loan.formatdate(loan.getloandate()) << '\n';
            file << loan.formatdate(loan.getduedate()) << '\n';
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
            int num = books[choice-1].getAvailableNum();
            if (num > 0)
            books[choice-1].setAvailableNum(--(num));
            else
                books[choice-1].setAvailableNum(0);


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
                books[choice - 1].setAvailableNum(tavb);
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
void Librarian ::processLoanRequest(){
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
        getline(file, line); tempLoan.setname(line);
        getline(file, line); tempLoan.setID(line);
        getline(file, line); tempLoan.setloandate(tempLoan.stringToTime(line));
        getline(file, line); tempLoan.setduedate(tempLoan.stringToTime(line));
        getline(file, line);
        if(line == "0")
            tempLoan.setloanstatus(0);
        else
            tempLoan.setloanstatus(1);
        loans.push_back(tempLoan);  // Add book to vector
    }
    file.close();  // Close the file

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

    fstream file2("Books.txt", ios::in);  // Open file for reading

    if (!file2.is_open()) {
        cout << "Unable to open file number 1." << endl;
        return;
    }
    // Read books from file
    string line2;
    vector<Book> books;
    while (getline(file2, line2)) {
        Book tempBook;
        tempBook.setISBN(line2);
        getline(file2, line2); tempBook.setTitle(line2);
        getline(file2, line2); tempBook.setAuthor(line2);
        getline(file2, line2); tempBook.setPublisher(line2);
        int genreValue;
        file2 >> genreValue;  // Read genre as integer
        file2.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear newline character
        Genre genre = static_cast<Genre>(genreValue);  // Convert integer to Genre enum
        tempBook.setGenre(genre);

        int availableNum;  // Declare variable to store availableNum
        file2 >> availableNum;  // Read availableNum as integer
        file2.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear newline character
        tempBook.setAvailableNum(availableNum);  // Set availableNum for the book

        books.push_back(tempBook);  // Add book to vector
    }
    file2.close();

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

        // Write remaining books back to file
        file.open("Books.txt", ios::out | ios::trunc);  // Open file for writing (truncating the existing content)
        if (!file.is_open()) {
            cout << "Unable to open file number 2." << endl;
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


        // Write remaining books back to file
        file.open("Loan.txt", ios::out | ios::trunc);  // Open file for writing (truncating the existing content)
        if (!file.is_open()) {
            cout << "Unable to open file." << endl;
            return;
        }

        for (auto& loan : loans) {
            file << loan.getISBN() << '\n';
            file << loan.getTitle() << '\n';
            file << loan.getAuthor() << '\n';
            file << loan.getname() << '\n';
            file << loan.getID() << '\n';
            file << loan.formatdate(loan.getloandate()) << '\n';
            file << loan.formatdate(loan.getduedate()) << '\n';
            file << loan.getloanstatus() << '\n';

        }
        file.close();  // Close the file
        cout << "Book removed successfully." << endl;
    } else {
        cout << "Invalid choice." << endl;
    }

}
void Librarian::generateReports(){}


//End of Librarian Derived class functions
//-----------------------------------------------