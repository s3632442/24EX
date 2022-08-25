#include "Node.h"

Node::Node()
{
    this->data = nullptr;
    this->next = nullptr;
}

Node::~Node()
{
}

Node::Node(Patient *n)
{
    this->data = n;
    this->next = nullptr;
}

Patient *Node::getData()
{
    return this->data;
}

Node *Node::getNext()
{
    return this->next;
}
void Node::setNext(Node *n)
{
    next = n;
}

void Node::printData()
{
    this->getData()->printWardAndShape();
}