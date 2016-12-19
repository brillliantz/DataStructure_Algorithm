#ifndef ADT_LINKEDLIST_H
#define ADT_LINKEDLIST_H

template <typename T>
class Node {
    public:
        T data;
        Node<T> *next;
        Node<T> *prev;
    public:
        Node(T value, Node<T> *n = nullptr, Node<T> *p = nullptr);
};

template <typename T>
class LinkedList {
    private:
        //Node<T> *head = nullptr;
        Node<T> *tail = nullptr;
        int length;

    public:
        Node<T> *head = nullptr;
        LinkedList();

        int size() const {return length;};
        bool empty() const {return (length == 0);}

        Node<T> *begin() const {return head->next;}
        Node<T> *end() const {return tail;}

        T front() const {return head->data;}
        void print() const;

        void push_back(T value);
        void push_front(T value);
        int pop_front();
        void clear();
        void structure() const;
        Node<T> *at(int n) const;
};

#include "adt_linkedlist.cpp"
#endif
