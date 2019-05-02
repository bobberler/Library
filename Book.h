/*
Author: Tom Lumsden
Project name: book.h
Project Description: book definitions
Date created: 4/1/2019
Date modified: 4/11/2019
*/

#ifndef BOOK_H
#define BOOK_H
#include <iostream>

using namespace std;

class Book
{
    public:
        Book();
        virtual ~Book();

        void display ();

        void setTitle (string _title);
        string getTitle ();

        void setAuthor (string _author);
        string getAuthor ();

        void setNumOfPages (string _numOfPages);
        string getNumOfPages ();

    protected:

    private:
        string title;
        string author;
        string numOfPages; //string because I wont be doing any calculations
};

#endif // BOOK_H
