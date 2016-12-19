#ifdef ADT_LINKEDLIST_H

#include <iostream>

using namespace std;

template <typename T>
Node<T>::Node(T value, Node<T> *n, Node<T> *p) :
    data{value}, next{n}, prev{p}
{ }

template <typename T>
LinkedList<T>::LinkedList() :
    length{0} {
        head = new Node<T>(0);
        tail = new Node<T>(0);
        head->next = tail;
        tail->prev = head;
    }

template <typename T>
void LinkedList<T>::print() const {
    if (this->empty()) {
        cout << "(empty now)." << endl;
    }
    else {
        cout << "===-Now printing all data in the linkedlist:" << endl;
            for (Node<T> *ptr = begin(); ptr != end(); ptr = ptr->next)
            {
                cout << ptr->data << ", ";
            }
            cout << endl;
    }
}

template <typename T>
void LinkedList<T>::push_back(T value)
{
    Node<T> *node = new Node<T>(value, tail, tail->prev);
    tail->prev = tail->prev->next = node;
    ++(this->length);
}

template <typename T>
void LinkedList<T>::push_front(T value)
{
    Node<T> *node = new Node<T>(value, head->next, head);
    head->next = head->next->prev = node;
    ++length;
}

template <typename T>
int LinkedList<T>::pop_front()
{
    Node<T> *p = begin();
    int data = p->data;
    head = p->next;
    p->next->prev = head;
    delete p;
    --length;
    return data;
}

template <typename T>
void LinkedList<T>::clear()
{
    while(!empty()) {
        pop_front();
    }
}

template <typename T>
void LinkedList<T>::structure() const
{
    cout << "=-Now printing the structure of the LinkedList"
         << ", structure format is #. data@[address]" << endl;

    int count = 0;
    for (Node<T> *p = this->head; p != nullptr; p = p->next)
    {
        cout << count << ". " << p->data << "@[" << p << "] --> ";
        if (count % 7 == 6) cout << endl;
        ++count;
    }
    cout << "nullptr" << endl;
}

template <typename T>
Node<T> *LinkedList<T>::at(int n) const
{
    if (n > this->length) return nullptr;

    int i = 0;
    Node<T> *p = begin();
    while (i != n) {
        p = p->next;
        ++i;
    }
    return p;
}

#endif
