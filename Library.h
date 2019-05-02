/*
Author: Tom Lumsden
Project name: library.h
Project Description: library definitions
Date created: 4/1/2019
Date modified: 4/11/2019
*/

#ifndef LIBRARY_H
#define LIBRARY_H
#include "Book.h"
#include "LinkedList.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Library
{
    public:
        Library();
        virtual ~Library();

        void modifyBook();
        Link* displayReturnLink ();
        void display ();
        void setLibrary (LinkedList* _library);
        LinkedList* getLibrary ();
        void addBook (Book);
        string to_upper (string _search);
        void searchBook ();
        void save (string path);
        void load (string path);

    protected:

    private:
        LinkedList* library;

};

#endif // LIBRARY_H
