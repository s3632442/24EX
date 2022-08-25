#ifndef S3632442_LINKEDLIST_H
#define S3632442_LINKEDLIST_H
#include <iostream>
#include "Node.h"

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    void addEnd(Patient *n);
    void printAll();
    void removeEnd();
    void addFront(Patient *n);
    Patient *removeFront();
    bool nodeExists(Patient);
    int frequency(Patient *);
    int getLength();
    Node *getNodeByData(Patient);
    Node *getNodeByIndex(int);
    void removeNodeAtIndex(int);
    // void removeNodeContaining(Patient);
    void removeNodeContaining(Patient *&);
    Node *getHead();

private:
    Node *head;
    Node *tail;
    int length;
};

#endif