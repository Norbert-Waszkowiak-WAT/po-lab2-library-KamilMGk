#ifndef BOOK
#define BOOK
#include <iostream>
 
using namespace std;
class Book{
private:
    string title;
    string author;
    string isbn;
public:
Book(string title, string author, string isbn):title(title),author(author),isbn(isbn){}
~Book(){cout << "Destroying book: "<< title << endl;}
string getTitle(){return title;}
string getAuthor(){return author;}
string getIsbn(){return isbn;}
};
#endif
