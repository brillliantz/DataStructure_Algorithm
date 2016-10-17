#ifdef ADT_LINKEDLIST_H
#define ADT_LINKEDLIST_H

class Node
{
    public:
        int data;
        Node *next;
        Node *before;
    public:
        Node(int value);
}

class LinkedList
{
    private:
        Node *head;
        int length;

    public:
        LinkedList();
        ~LinkedList();

        /*
         * methods
         */
}

#endif
