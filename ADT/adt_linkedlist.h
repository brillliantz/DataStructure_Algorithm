#ifndef ADT_LINKEDLIST_H
#define ADT_LINKEDLIST_H

class Node {
    public:
        int data;
        Node *next;
        Node *prev;
    public:
        explicit Node(int value, Node *n = nullptr, Node *p = nullptr);
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

        int size() const {return length;};
        bool empty() const {return (length == 0);}

        Node *begin() const {return head->next;}
        Node *end() const {return tail;}

        int front() const {return head->data;}
        void print() const;

        void push_back(int value);
        void push_front(int value);
        int pop_front();
        void clear();
        void structure() const;
        Node *at(int n) const;
};

#endif
