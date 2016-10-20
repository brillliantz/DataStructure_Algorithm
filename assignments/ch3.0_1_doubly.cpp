#include "/home/william/git_repo/DataStructure_Algorithm/ADT/adt_linkedlist.h"
#include <stdexcept>

void Swap(Node *head, Node *x1) {
    /**
     *  swap node x1 and the node after it in a
     *  singly linked list without exchanging their data
     */
    Node *x2 = x1->next;
    if (!x2)
        throw std::range_error("LinkedList::swap's param x1 can't be the tail.");

    if (x1 == head)
    {
        Node *right = x2->next;
        x2->before = nullptr;
        x2->next = x1;
        x1->next = right;
        x1->before = x2;
    }
    else
    {
        Node *left = x1->before, *right = x2->next;

        left->next = x2;
        right->before = x1;
        x1->next = right;
        x1->before = x2;
        x2->next = x1;
        x2->before = left;
    }
}
