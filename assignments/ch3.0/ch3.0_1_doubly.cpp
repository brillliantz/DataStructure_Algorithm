/**
*  swap node x1 and the node after it in a
*  doubly linked list without exchanging their data
*/

#include "./utils/adt_linkedlist.h"
#include <stdexcept>

template <typename T>
void Swap_doubly(Node<T> *head, Node<T> *x1) {
    /**
     *  swap node x1 and the node after it in a
     *  singly linked list without exchanging their data
     */
    Node<T> *x2 = x1->next;
    if (!x2)
        throw std::range_error("LinkedList::swap's param x1 can't be the tail.");

    if (x1 == head)
    {
        Node<T> *right = x2->next;
        x2->prev = nullptr;
        x2->next = x1;
        x1->next = right;
        x1->prev = x2;
    }
    else
    {
        Node<T> *left = x1->prev, *right = x2->next;

        left->next = x2;
        right->prev = x1;
        x1->next = right;
        x1->prev = x2;
        x2->next = x1;
        x2->prev = left;
    }
}
