

#ifndef LIBRARYMANAGEMENT_H
#define LIBRARYMANAGEMENT_H
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>
#include <algorithm> // for std::all_of
#include <cctype>    // for std::isdigit
#include <vector>

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

std::string genreToString(Genre genre);

std::string genreToString(int genre);

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
    void setISBN(const string num);
    void setTitle(const string n);
    void setAuthor(const string n);
    void setGenre(const int n);
    void setPublisher(const string n);
    void setAvailableNum(int n);

    string getISBN()const;
    string getTitle()const;
    string getAuthor()const;
    string getPublisher()const;
    int getGenre()const;
    int getAvailableNum()const;


};
#endif //LIBRARYMANAGEMENT_H
