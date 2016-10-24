/*  return the union of
 *  two sorted singly linked list.
 *  using linkedlist
*/
#include "./utils/adt_linkedlist.h"

Node* Union_noSTL(Node* l1, Node* l2) {
    Node *dummy = new Node(0);
    Node *p1 = l1, *p2 = l2, *tail = dummy;

    while (p1 && p2 ) {
        if (p1->data > p2->data) {
            tail->next = p2;
            p2 = p2->next;
        }
        else if (p1->data < p2->data) {
            tail->next = p1;
            p1 = p1->next;
        }
        else {
            tail->next = p1;
            p1 = p1->next;
            // uncomment following two line to merge (not union)
            //tail = tail->next;
            //tail->next = p2;
            p2 = p2->next;
        }
        tail = tail->next;
    }
    while (p1) {
        tail->next = p1;
    }
    while (p2) {
        tail->next = p2;
    }
    return dummy->next;
}
