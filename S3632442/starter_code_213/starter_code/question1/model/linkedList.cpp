#include <iostream>
#include "linkedList.h"

LinkedList::LinkedList()
{
    this->head = NULL;
    this->tail = NULL;
    this->length = 0;
}
LinkedList::~LinkedList()
{
    delete head;
    delete tail;
}

int LinkedList::getLength()
{
    return this->length;
};

void LinkedList::printAll()
{

    node *temp = head;

    if (temp == NULL)
    {
        std::cout << "the list is empty\n";
    }
    else
    {
        while (temp != NULL)
        {
            std::cout << temp->getData() << std::endl;
            temp = temp->getNext();
        }
    }
}
void LinkedList::addEnd(int n)
{

    node *temp = new node(n);

    if (this->head == NULL)
    {

        this->head = temp;
        this->tail = temp;
    }
    else
    {
        this->tail->setNext(temp);
        tail = temp;
    };
};

void LinkedList::removeEnd()
{
    if (this->head == NULL)
    {
        return;
    }
    node *temp = head;
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

void LinkedList::addFront(int n)
{
    node *temp = new node(n);

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

void LinkedList::removeFront()
{
    if (this->head == NULL)
    {
        return;
    }
    else if (head == tail)
    {
        this->head = NULL;
        this->tail = NULL;
    }
    else
    {
        node *temp = head;
        head = head->getNext();
        delete temp;
    }
    this->length--;
}

bool LinkedList::search(int i)
{
    node *temp = head;

    if (temp != NULL)
    {
        while (temp != NULL)
        {
            if (temp->getData() != i)
            {

                temp = temp->getNext();
                return false;
            }
            else
            {
                return true;
            }
        }
    }
    return false;
}

int LinkedList::at(int i)
{

    try
    {

        node *temp = head;

        if (temp != NULL)
        {
            while (temp != NULL)
            {
                if (temp->getData() != i)
                {

                    temp = temp->getNext();
                }
                else if (temp->getData() == i)
                {

                    return temp->getData();
                }
            }
        }
        throw std::invalid_argument("\nINDEX OUT OF BOUNDS EXCEPTION\n");
    }

    catch (std::invalid_argument &e)
    {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}
