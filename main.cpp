#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <algorithm> // for std::all_of
#include <cctype>    // for std::isdigit
#include <vector>
/*
hello niggas this is abdo here soooo i changed some stuff in the addbook function
so we can add a genre using an enum, i added an enum class for the genre but tbh i'd rather
we just enter the genre as is since the enum just makes it more complicated, but who cares.

Also the remove book function i made it using chatgpt since am not that smart but, it basically
copies all the data in the text file into a vector then it deletes the book the user chooses,
and writes the remaining books back in the file

I ALso did the getters in the book class since they were required for the remove book function.
 */

using namespace std;

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

class Book{
private:
    string ISBN; // Easier to use as String, otherwise it would long int, which is incompatible with some functions
    string title;
    string author;
    string publisher;
    Genre genre;
    int publicationYear;
    bool availabilityStatus;
    int available;

public:
    void setISBN(const string num){
        ISBN = num;
    }
    void setTitle(const string n){
        title = n;
    }
    void setAuthor(const string n){
        author = n;
    }
    void setPublisher(const string n){
        publisher = n;
    }

    string getISBN() const {
        return ISBN;
    }
    string getTitle() const {
        return title;
    }
    string getAuthor() const {
        return author;
    }
    string getPublisher() const {
        return publisher;
    }

    // Getter and Setter methods for each member variable
    void setGenre(Genre g) { genre = g; }
    Genre getGenre() const { return genre; }
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
        streampos pos = 0;
        string readLine;
        ifstream readFile("Books.txt");
        ofstream writeFile("Search_Results.txt");
        if (readFile.is_open()){
            while(!readFile.eof()) {

                getline(readFile, readLine);

                cout << readLine<< endl;

                if (readLine == "-1") {
                    pos = readFile.tellg();
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

            cout << "Enter the Author's name: ";
            getline(cin, Input);
            tempBook.setAuthor(Input);
            file << Input << '\n';

            cout << "Enter the Publisher: ";
            cin >> Input;
            tempBook.setPublisher(Input);
            file << Input << '\n';

            //To print -1 in the text file(for the search function ig)
            file << "-1" << '\n';

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
            int genreValue;
            file >> genreValue;  // Read genre as integer
            file.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear newline character
            Genre genre = static_cast<Genre>(genreValue);  // Convert integer to Genre enum
            tempBook.setGenre(genre);

            getline(file, line); tempBook.setAuthor(line);
            getline(file, line); tempBook.setPublisher(line);


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
            books.erase(books.begin() + choice - 1);  // Remove selected book from vector

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
            }
            file.close();  // Close the file
            cout << "Book removed successfully." << endl;
        } else {
            cout << "Invalid choice." << endl;
        }
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
    /*Librarian librarian;
    librarian.addBook();
    librarian.addBook();
    librarian.addBook();
    librarian.removeBook();
    cout<<"Hello World";*/

   Member mem;
   mem.searchBooks("Morad");

    return 0;
}

