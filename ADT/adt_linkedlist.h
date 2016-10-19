#ifdef ADT_LINKEDLIST_H
#define ADT_LINKEDLIST_H

class Node
{
    public:
        int data;
        Node *next;
        Node *before;
    public:
        explicit Node(int value = 0);
};

class LinkedList
{
    private:
        Node *head;
        int length;

    public:
        explicit LinkedList();
        ~LinkedList();

        /*
         * methods
         */
};

#endif
