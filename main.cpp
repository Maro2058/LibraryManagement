#include <iostream>

using namespace std;

class Member{
private:
    string userID;
    string userName;
    int pass;

public:
    void login(){
        cout << " Enter User ID" << endl;
        cout << "Enter Password" << endl;
    }
    void manageAccount(){

    }
    void searchBooks(){

    }
};

class Book{
private:
    int ISBN;
    string title;
    string author;
    enum genre {HealthAndNutrition, Physics, Biology, Chemistry, Engineering, ComputerScience, Art, Music, Mathematics, BusinessAndEconomics, Psychology, Education,  Language};

public:
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
    Book addBook(){

    }
    void removeBook(Book& book){

    }
    void updateBook(){

    }
    void viewMembers(){

    }
    void addMember(){
        Member* mmbrRef = new Member;
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

public:
};

int main()
{
    cout<<"Hello World";

    return 0;
}
