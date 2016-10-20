#ifndef ADT_LINKEDLIST_H
#define ADT_LINKEDLIST_H

class Node {
    public:
        int data;
        Node *next;
        Node *before;
    public:
        explicit Node(int value);
};

class LinkedList {
    private:
        //Node *head = nullptr;
        Node *tail = nullptr;
        int length;

    public:
        Node *head = nullptr;
        explicit LinkedList();
        ~LinkedList();
        int size() const;
        bool empty() const;
        void clear();
        void print() const;

        void push_back(int value);
        void push_front(int value);
        void pop_front();
        int front() const;
        void structure() const;
        Node *at(int n) const;
        /*
         * methods
         */
};

#endif
