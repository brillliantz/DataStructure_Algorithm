#include <iostream>
#include "adt_linkedlist.h"

using namespace std;

Node::Node(int value, Node *n, Node *p) :
    data{value}, next{n}, prev{p}
{ }

LinkedList::LinkedList() :
    length{0} {
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
    }

LinkedList::~LinkedList()
{
    cout << "\nPrinting in the destructor func. (do nothing)"<<endl;
}

void LinkedList::print() const
{
    cout << "=-Now printing all data in the linkedlist:" << endl;
    for (Node *ptr = begin(); ptr != end(); ptr = ptr->next)
    {
        cout << ptr->data << ", ";
    }
    cout << endl;
}

void LinkedList::push_back(int value)
{
    Node *node = new Node(value, tail, tail->prev);
    tail->prev = tail->prev->next = node;
    ++(this->length);
}

void LinkedList::push_front(int value)
{
    Node *node = new Node(value, head->next, head);
    head->next = head->next->prev = node;
    ++length;
}
int LinkedList::pop_front()
{
    Node *p = begin();
    int data = p->data;
    head = p->next;
    p->next->prev = head;
    delete p;
    --length;
    return data;
}

void LinkedList::clear()
{
    while(!empty()) {
        pop_front();
    }
}

void LinkedList::structure() const
{
    cout << "=-Now printing the structure of the LinkedList"
         << ", structure format is #. data@[address]" << endl;

    int count = 0;
    for (Node *p = this->head; p != nullptr; p = p->next)
    {
        cout << count << ". " << p->data << "@[" << p << "] --> ";
        if (count % 7 == 6) cout << endl;
        ++count;
    }
    cout << "nullptr" << endl;
}

Node *LinkedList::at(int n) const
{
    if (n > this->length) return nullptr;

    int i = 0;
    Node *p = begin();
    while (i != n)
    {
        p = p->next;
        ++i;
    }
    return p;
}
