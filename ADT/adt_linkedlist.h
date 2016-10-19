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
        Node *head = nullptr;
        Node *tail = nullptr;
        int length;

    public:
        explicit LinkedList();
        ~LinkedList();
        int size() const;
        bool empty() const;
        void print() const;
        void append(int value);
        /*
         * methods
         */
};

#endif
