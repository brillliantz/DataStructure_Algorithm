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
    Node *left;

    if (x1 == head)
    {
        //TODO if the LinkedList does not have a header node, then
        //we have to modify "head" of the linked list.
        x1->next = x2->next;
        x2->next = x1;
    }
    else
    {
        for (left = head; left->next != x1; left = left->next) {
            ;
        }
        x1->next = x2->next;
        left->next = x2;
        x2->next = x1;
    }
}
