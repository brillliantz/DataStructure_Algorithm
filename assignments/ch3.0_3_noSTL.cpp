#include <iostream>
#include "../ADT/adt_linkedlist.h"

Node* mergeTwoLists(Node* l1, Node* l2) {
    Node *res_head = new Node(0);
    Node *p1 = l1, *p2 = l2, *tail = res_head;
    while (p1 && p2 ) {
        if (p1->data < p2->data) {
            tail->next = p2;
            p2 = p2->next;
        }
        else if (p1->data > p2->data) {
            tail->next = p1;
            p1 = p1->next;
        }
        else {
            tail->next = p1;
            p1 = p1->next;
            tail = tail->next;
            tail->next = p2;
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
    return res_head->next;
}
