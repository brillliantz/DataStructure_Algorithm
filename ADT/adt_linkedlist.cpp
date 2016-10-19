#include <iostream>
#include "adt_linkedlist.h"

using namespace std;

Node::Node(int value) {
    this->data = value;
    this->next = nullptr;
    this->before = nullptr;
}

LinkedList::LinkedList()
{
    this->length = 0;
    this->head = nullptr;
}

LinkedList::~LinkedList()
{
    ;
}

int LinkedList::size() const
{
    return this->length;
}

bool LinkedList::empty() const
{
    return (this->length == 0);
}

void LinkedList::print() const
{
    for (Node *ptr = this->head; ptr != nullptr; ptr = ptr->next)
    {
        cout << ptr->data << ", ";
    }
    cout << endl;
}

void LinkedList::append(int value)
{
    if (this->head == nullptr)
    {
        Node *node = new Node(value);
        this->head = node;
    }
    else
    {
        Node *tail;
        for (tail = this->head; tail != nullptr; tail = tail->next)
        {
            ;
        }
        Node *node = new Node(value);
        tail->next = node;
    }
    ++(this->length);
}

