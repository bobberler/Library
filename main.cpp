/*
Author: Tom Lumsden
Project name: library
Project Description: A program that will mimic a library.
                     It will have functionality for the librarian (adding and deleting books from the library)
                     and for the users (borrowing and returning books).
Date created: 4/1/2019
Date modified: 4/11/2019
*/
//=========================================================================================================================
//
#include <iostream>
#include <string>

#include "Library.h"
#include "Book.h"

using namespace std;

void customer();

void librarian();


int main()
{
    string type_of_person = ""; //user or librarian
    cout << "Welcome to the library\n";
    cout << "Are you a [customer] or [librarian]\n";
    cin >> type_of_person;
    system("CLS");
    if ( type_of_person == "customer")//user is a customer
    {
        customer();
    }
    else if ( type_of_person == "librarian")//user is a librarian
    {
        librarian();
    }
    return 0;
}

void customer()
{
    int choice = 0;
    bool exit = false;
    Library library;
    Library customersBooks;
    library.load("library.txt"); //load library
    customersBooks.load("customer.txt"); //load customers taken out books
    while (!exit)
    {
        cout << "Hello customer, what do you want to do?\n"
        << "1. Examine our library's contents\n"
        << "2. Search for a book based on its properties\n"
        << "3. Borrow a book\n"
        << "4. Return a book\n"
        << "5. Exit the library\n";
        cin >> choice;
        switch (choice)
        {
            case 1: //examine
                {
                   library.display(); //display library
                   if (customersBooks.getLibrary()->isEmpty() == false) //display customer library
                   {
                        cout << endl << endl;
                        cout << "Book you currently have taken out: \n";
                        customersBooks.display();
                   }
                   system("PAUSE");
                }
                break;

            case 2: //search
                {
                    library.searchBook();
                    system("PAUSE");
                }
                break;


            case 3: //borrow
                {
                    if(library.getLibrary()->isEmpty()==true)
                    {
                        cout << "the library is empty\n";
                        system("PAUSE");
                    }
                    else
                    {
                        Link* borrow;
                        borrow = library.displayReturnLink();
                        if (borrow != NULL)
                        {
                            customersBooks.addBook(borrow->contents); //add book to customer library
                            library.getLibrary()->remove(borrow); //remove from library
                        }
                    }
                }
                break;

            case 4: //return
                {
                    if(customersBooks.getLibrary()->isEmpty() == true)
                    {
                        cout << "you have no books to return\n";
                        system("PAUSE");
                    }
                    else
                    {
                        Link* returning;
                        returning = customersBooks.displayReturnLink();
                        if (returning != NULL)
                        {
                            library.addBook(returning->contents); //add to library
                            customersBooks.getLibrary()->remove(returning); //remove from customer library
                        }
                    }
                }
                break;

            case 5: //exit
                {
                    exit = true;
                }
                break;
        }
        customersBooks.save("customer.txt");
        library.save("library.txt");
        system("CLS");
    }

    return;
}

void librarian()
{
    Library library;
    library.load("library.txt");
    int choice = 0;
    bool exit = false;
    while (!exit)
    {
        cout << "Hello librarian, what do you want to do?\n"
        << "1. Add books to the library collection\n"
        << "2. Remove books from the library collection\n"
        << "3. Modify the properties of a specific book\n"
        << "4. Examine the library\n"
        << "5. Exit the library\n";
        cin >> choice;
        switch (choice)
        {
            case 1: // add
                {
                    Book book; //temp book
                    string line = "";
                    cout << "What is the title?";
                    getline (cin >> ws, line);
                    book.setTitle(line);
                    cout << "Who is the author?";
                    getline (cin >> ws, line);
                    book.setAuthor(line);
                    cout << "How many pages are there?";
                    getline (cin >> ws, line);
                    book.setNumOfPages(line);
                    library.addBook(book); //add book to library
                }
                break;

            case 2://remove
                {
                    Link* link;
                    link = library.displayReturnLink();
                    if (link != NULL)
                    {
                        library.getLibrary()->remove(link);
                    }
                }
                break;

            case 3://modify
                {
                    library.modifyBook();
                }
                break;

            case 4:
                {
                    library.display();
                    system("PAUSE");
                }
                break;

            case 5: //exit
                {
                    exit = true;
                }
                break;
        }
        library.save("library.txt");
        system("CLS");
    }

    return;
}

