/*
Author: Tom Lumsden
Project name: library.cpp
Project Description: library functions
Date created: 4/1/2019
Date modified: 4/11/2019
*/

#include "Library.h"

Library::Library()
{
    library = new LinkedList;
    //ctor
}

Library::~Library()
{
    //dtor
}



void Library::setLibrary (LinkedList* _library)
{
    library = _library;
    return;
}

LinkedList* Library::getLibrary ()
{
    return library;
}

void Library::addBook(Book _book) //add book to library
{
    library->add(_book, library->getLast());
    return;
}

string Library::to_upper(string _search) //make a string all uppercase
{
   char temp[100];
   for(int i = 0; i < _search.length(); i++)
   {
           temp[i] = toupper(_search[i]);
   }
   return temp;
}

Link* Library::displayReturnLink () //display all books and return the link of the chosen book
{
    if (library->isEmpty() == true)
    {
        cout << "the library is empty\n";
        system("PAUSE");
        return NULL;
    }
    int choice;
    Link* link;
    link = library->getFirst();
    for (int i = 0; i < library->getSize(); i++)
    {
        cout << i+1 << ": ";
        link->contents.display();
        link = link->next;
    }
    cout << library->getSize() + 1 << ": exit\n";
    cin >> choice;
    if (choice == library->getSize()+1)
    {
        return NULL;
    }
    link = library->getFirst();
    for (int i = 0; i < choice-1; i++)
    {
        link = link->next;
    }
    return link;
}

void Library::display () //display all books
{
    if (library->isEmpty() == true)
    {
        cout << "the library is empty\n";
        return;
    }
    Link* link;
    link = library->getFirst();
    for (int i = 0; i < library->getSize(); i++)
    {
        link->contents.display();
        link = link->next;
    }
    return;
}

void Library::searchBook ()
{
    if (library->isEmpty() == true)
    {
        cout << "the library is empty\n";
        return;
    }
    bool found = false;
    string search = "";
    Link* temp;
    temp = library->getFirst();
    cout << "Please enter your search:\n(spelling matters)\n";
    getline (cin >> ws, search); // spaces become part of input/search
    for (int i = 0; i < library->getSize(); i++) //
    {
        if (to_upper(search) == to_upper(temp->contents.getTitle()) or //to_upper makes both strings all capital so capitilization doesnt matter
            to_upper(search) == to_upper(temp->contents.getAuthor()) or  //in the search
            to_upper(search) == to_upper(temp->contents.getNumOfPages()))// if the search is the same as a title, author, number of pages
            {
                temp->contents.display();
                found = true;
            }
            temp = temp->next;
    }
    if (found == false)
    {
        cout << "No books found base on your search\n";
    }
    return;
}

void Library::modifyBook () //remove the book, modify it, put it back.
{
    if (library->isEmpty() == true)
    {
        cout << "the library is empty\n";
        system("PAUSE");
        return;
    }
    int modifyType = 0;
    bool exit = false;
    string change;
    Link* link;
    link = displayReturnLink();
    if (link == NULL)
    {
        return;
    }
    library->remove(link);
    while (!exit)
    {
        cout << "What do you want to modify: \n";
        cout << "1. Title\n";
        cout << "2. Author\n";
        cout << "3. Number of pages\n";
        cout << "4. Exit\n";
        cin >> modifyType;
        switch (modifyType)
        {
            case 1://title
                cout << "What is the new title\n";
                getline (cin >> ws, change);
                link->contents.setTitle(change);
                break;

            case 2://author
                cout << "Who is the new author\n";
                getline (cin >> ws, change);
                link->contents.setAuthor(change);
                break;

            case 3://pages
                cout << "What is the new number of pages\n";
                getline (cin >> ws, change);
                link->contents.setNumOfPages(change);
                break;

            case 4://exit
                addBook(link->contents);
                exit = true;
                break;
        }
    }

    return;
}

void Library::save (string path)
{
    Link* link;
    fstream saveFile;
    if (!ifstream (path)) // make the file if it does not exist
    {
        saveFile.open(path, fstream::out);
        saveFile.close();
    }
    if (library->isEmpty() == true)
    {
        return;
    }
    saveFile.open(path, ios::out | ios::trunc);// opens file and overwrites everything
    link = library->getFirst();
    for (int i = 0; i < library->getSize(); i++) //cycle through books
    {
        if (link != NULL)
        {
            saveFile << link->contents.getTitle() << endl;
            saveFile << link->contents.getAuthor() << endl;
            saveFile << link->contents.getNumOfPages() << endl;
            link = link->next;
        }
    }

    saveFile.close(); // closes file
    return;
}

void Library::load (string path)
{
    Book book;
    string line;
    fstream saveFile;
    if (!ifstream (path)) // make the file if it does not exist
    {
        saveFile.open(path, fstream::out);
        saveFile.close();
    }
    saveFile.open(path, fstream::in); // opens file
    while (!saveFile.eof()) //while not the end of the file
    {
        getline(saveFile, line);
        if (line != "")
        {
            book.setTitle(line); // add to temp book
            getline(saveFile, line); // get author
            book.setAuthor(line);// add to temp book
            getline(saveFile, line); // get number of pages
            book.setNumOfPages(line);// add to temp book
            addBook(book); //add book to library
        }

    }

    saveFile.close(); // closes file
    return;
}
