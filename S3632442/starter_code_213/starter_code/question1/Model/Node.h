#ifndef S3632442_NODE_H
#define S3632442_NODE_H

#include "Patient.h"
#include <iostream>

class Node
{
public:
    Node();
    Node(Patient *n);
    ~Node();
    Patient *getData();
    Node *getNext();
    void setNext(Node *);
    void printData();

private:
    Patient *data;
    Node *next;
};

#endif // S3632442_NODE_H
