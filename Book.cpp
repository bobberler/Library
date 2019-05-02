/*
Author: Tom Lumsden
Project name: book.cpp
Project Description: book functions
Date created: 4/1/2019
Date modified: 4/11/2019
*/
//=========================================================================================================================

#include "Book.h"

Book::Book()
{
    //ctor
}

Book::~Book()
{
    //dtor
}

void Book::display ()
{
    cout << "Title: " << getTitle() << ", ";
    cout << "Author: " << getAuthor() << ", ";
    cout << "Number of pages: " << getNumOfPages() << endl;
}

void Book::setTitle (string _title)
{
    title = _title;
    return;
}

string Book::getTitle ()
{
    return title;
}

void Book::setAuthor (string _author)
{
    author = _author;
    return;
}

string Book::getAuthor ()
{
    return author;
}

void Book::setNumOfPages (string _numOfPages)
{
    numOfPages = _numOfPages;
    return;
}

string Book::getNumOfPages ()
{
    return numOfPages;
}
