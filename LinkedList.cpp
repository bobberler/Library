/*
Author: Tom Lumsden
Project name: LinkedList.cpp
Project Description: linked list functions
Date created: 4/1/2019
Date modified: 4/11/2019
*/
//=========================================================================================================================

#include "LinkedList.h"

LinkedList::LinkedList()
{
    size = 0;
    first = NULL;
    last = NULL;
}

LinkedList::~LinkedList()
{
    //dtor
}

void LinkedList::add(Link* newLink, Link* destination) //Adds the new Link after destination
{
    size++;

    if(first == NULL)
    {
        newLink->next = NULL;
        newLink->previous = NULL;

        first = newLink;
        last = newLink;
    }
    else if(destination == last)
    {
        newLink->next = NULL;
        newLink->previous = destination;

        destination->next = newLink;

        last = newLink;
    }
    else
    {
        newLink->next = destination->next;
        newLink->previous = destination;

        destination->next->previous = newLink;
        destination->next = newLink;
    }
}

void LinkedList::add(Book newContent, Link* destination)
{

    Link* l = new Link;
    l->contents = newContent;

    add(l, destination);
}

Link* LinkedList::remove(Link* link)
{
    if(first == NULL) //Chain is empty
        return link;
    if (link == NULL)
        return link;

    size--;

    if(first == link && last == link) //If the link the the only one in the chain
    {
        first = NULL;
        last = NULL;
    }
    else if(first == link) //link is the first in the chain
    {
        link->next->previous = NULL;
        first = link->next;
    }
    else if(last == link) //link is the last in the chain
    {
        link->previous->next = NULL;
        last = link->previous;
    }
    else
    {
        link->previous->next = link->next;
        link->next->previous = link->previous;
    }

    link->next = NULL;
    link->previous = NULL;

    return link;
}

bool LinkedList::isEmpty()
{
    return (size < 1);
}

int LinkedList::getSize ()
{
    return size;
}

Link* LinkedList::getFirst ()
{
    return first;
}

Link* LinkedList::getLast ()
{
    return last;
}
