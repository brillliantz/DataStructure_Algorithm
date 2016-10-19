#include <iostream>
#include "adt_linkedlist.h"

using namespace std;

Node::Node(int value) :
    data{value}, next{nullptr}, before{nullptr}
{ }

LinkedList::LinkedList() :
    length{0}, head{nullptr}, tail{nullptr}
{ }

LinkedList::~LinkedList()
{
    cout << "\nPrinting in the destructor func. (do nothing)"<<endl;
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
    cout << "------Now printing all data in the linkedlist------" << endl;
    for (Node *ptr = this->head; ptr != nullptr; ptr = ptr->next)
    {
        cout << ptr->data << ", ";
    }
    cout << endl;
}

void LinkedList::append(int value)
{
    if (this->empty())
    {
        Node *node = new Node(value);
        this->head = node;
    }
    else
    {
        Node *ptr;
        for (ptr = this->head; ptr->next != nullptr; ptr = ptr->next)
        {
            ;
        }
        Node *node = new Node(value);
        ptr->next = node;
    }
    ++(this->length);
}

