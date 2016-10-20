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

void LinkedList::clear()
{
    Node *p1 = this->head;
    Node *p2 = p1->next;
    while (p2)
    {
        delete p1;
        p1 = p2;
        p2 = p1->next;
    }
    this->head = nullptr;
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

void LinkedList::push_back(int value)
{
    if (this->empty())
    {
        Node *node = new Node(value);
        this->head = node;
    }
    else
    {
        //Node *ptr;
        //for (ptr = this->head; ptr->next != nullptr; ptr = ptr->next)
        //{
        //    ;
        //}
        //Node *node = new Node(value);
        //ptr->next = node;
        Node *node = new Node(value);
        this->tail->next = node;
        this->tail = node;
    }
    ++(this->length);
}

void LinkedList::push_front(int value)
{
    Node *node = new Node(value);
    node->next = this->head;
    this->head->before = node;
    this->head = node;
}
void LinkedList::pop_front()
{
    Node *p = this->head;
    this->head = this->head->next;
    this->head->next->before = nullptr;
    delete p;
}

int LinkedList::front() const
{
    return this->head->data;
}

void LinkedList::structure() const
{
    cout << "======Now printing the structure of the LinkedList"
         << ", structure format is #. data@[address]" << endl;

    int count = 0;
    for (Node *p = this->head; p != nullptr; p = p->next)
    {
        cout << count << ". " << p->data << "@[" << p << "] --> ";
        if (count % 7 == 6) cout << endl;
        ++count;
    }
    cout << "nullptr" << endl << endl;
}

Node *LinkedList::at(int n) const
{
    if (n > this->length) return nullptr;

    int i = 0;
    Node *p = this->head;
    while (i != n)
    {
        p = p->next;
        ++i;
    }
    return p;
}
