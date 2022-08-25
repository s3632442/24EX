#ifndef likedList_H
#define likedList_H

#include "node.h"

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    void addEnd(int);
    void printAll();
    void removeEnd();
    void addFront(int);
    void removeFront();
    bool search(int);
    int getLength();
    int at(int);

private:
    node *head;
    node *tail;
    int length;
};

#endif