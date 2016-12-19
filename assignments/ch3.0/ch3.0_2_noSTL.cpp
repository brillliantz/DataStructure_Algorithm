/*  return the intersection of
 *  two sorted singly linked list.
 *  using linkedlist
*/
#include "./utils/adt_linkedlist.h"

template <typename T>
Node<T>* Intersection_noSTL(Node<T>* l1, Node<T>* l2) {
    Node<T> *dummy = new Node<T>(0);
    Node<T> *p1 = l1, *p2 = l2, *tail = dummy;

    while (p1 && p2 ) {
        if (p1->data > p2->data) {
            //std::cout << p1->data << ",a " << p2->data << std::endl;
            p2 = p2->next;
        }
        else if (p1->data < p2->data) {
            //std::cout << p1->data << ",b " << p2->data << std::endl;
            p1 = p1->next;
        }
        else if (p1->data == p2->data) {
            //std::cout << p1->data << ",c " << p2->data << std::endl;
            tail->next = p1;
            p1 = p1->next;
            p2 = p2->next;
            tail = tail->next;
        }
        else {
        }
    }
    return dummy->next;
}
