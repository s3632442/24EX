#include "PReg.h"
#include <iostream>

PReg::PReg()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->length = 0;
}
PReg::~PReg()
{
    delete head;
    delete tail;
}

int PReg::getLength()
{
    return this->length;
};

void PReg::printAll()
{
    Node *temp = head;

    if (temp == NULL)
    {
        std::cout << "the list is empty\n";
    }
    else
    {
        while (temp != NULL)
        {
            temp->printData();
            std::cout << std::endl;
            temp = temp->getNext();
        }
    }
}
void PReg::addEnd(Patient *n)
{
    if (!nodeExists(*n))
    {
        Node *temp = new Node(n);

        if (this->head == NULL)
        {

            this->head = temp;
            this->tail = temp;
        }
        else
        {
            this->tail->setNext(temp);
            tail = tail->getNext();
        };
        this->length++;
    }
    else
    {
        std::cout << "Cant Add " << n->regNo << " exists \n";
    }
};

void PReg::removeEnd()
{
    if (this->head == NULL)
    {
        return;
    }
    Node *temp = head;
    // try with a for
    while (temp->getNext() != tail)
    {
        temp = temp->getNext();
    }

    delete this->tail;
    temp->setNext(NULL);
    this->tail = temp;
    this->length--;
}

void PReg::addFront(Patient *n)
{
    if (!nodeExists(*n))
    {
        Node *temp = new Node(n);

        if (this->head == NULL)
        {
            this->head = temp;
            this->tail = temp;
        }
        else
        {
            temp->setNext(this->head);
            this->head = temp;
        }
        this->length++;
    }
    else
    {
        std::cout << "Cant Add " << n->regNo << " exists \n";
    }
}

Patient *PReg::removeFront()
{
    Patient *front = new Patient();
    if (this->head == NULL)
    {
    }
    else if (head == tail)
    {
        front = head->getData();
        this->head = NULL;
        this->tail = NULL;
    }
    else
    {
        Node *temp = head;
        front = head->getData();
        head = head->getNext();
        delete temp;
    }
    this->length--;
    return front;
}

bool PReg::nodeExists(Patient i)
{
    Node *temp = head;
    bool *exists = new bool(false);

    if (temp != NULL)
    {

        while (temp != NULL)
        {
            if (temp->getData()->getWard() != i.getWard())
            {
                temp = temp->getNext();
                *exists = false;
            }
            else
            {
                temp = NULL;
                *exists = true;
            }
        }
    }
    return *exists;
}

Node *PReg::getNodeByData(Patient d)
{
    Node *temp = head;
    bool *found = new bool(false);

    if (temp != NULL)
    {
        while (temp != NULL && !*found)
        {
            if (temp->getData()->getWard() != d.getWard())
            {

                temp = temp->getNext();
            }
            else
            {

                *found = true;
            }
        }
    }
    return temp;
}

Node *PReg::getNodeByIndex(int i)
{

    int Count = 0;

    Node *temp = head;
    Node *r = new Node();

    if (temp != NULL)
    {
        while (temp != NULL)
        {
            if (Count != i)
            {

                temp = temp->getNext();
            }
            else if (Count == i)
            {

                *r = *temp;
            }
            Count++;
        }
    }
    return r;
}

void PReg::removeNodeAtIndex(int n)
{
    Node *temp1 = head;
    Node *temp2;
    int i;

    for (i = 0; i < n - 2; i++)
    {
        temp1 = temp1->getNext();
    }
    if (n > 0)
    {
        temp2 = temp1->getNext();
        temp1->setNext(temp2->getNext());
        delete temp2;
    }
    else
    {
        removeFront();
    }
    length--;
}

void PReg::removeNodeContaining(Patient *&Patient)
{
    Node *temp = head;
    Node *prior = nullptr;

    if (temp != nullptr &&
        temp->getData()->getWard() == Patient->getWard())
    {
        // If head node's data matches Patient data
        head = temp->getNext();
        delete temp;
        length--;
    }
    else
    {
        int count = 0;
        while (temp != nullptr &&
               (temp->getData()->getWard() != Patient->getWard()))
        {
            // Searching while either ward or shape mismatches
            count++;
            prior = temp;
            temp = temp->getNext();
        }

        if (temp == nullptr)
        {
            // Wasn't found
        }
        else
        {
            // You are the weakest link. Goodbye.
            prior->setNext(temp->getNext());
            delete temp;
            length--;
        }
    }
}

int PReg::frequency(Patient *Patient)
{
    int count = 0;
    Node *temp = head;
    Ward PatientWard = Patient->getWard();

    while (temp != NULL)
    {
        Ward tempWard = temp->getData()->getWard();

        if (tempWard == PatientWard)
        {
            count++;
        }
        temp = temp->getNext();
    }
    return count;
}

Node *PReg::getHead()
{
    return head;
};
