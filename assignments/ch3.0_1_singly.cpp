#include "/home/william/git_repo/DataStructure_Algorithm/ADT/list_impl_ll.h"





void swap(Node *head, Node *x1, Node *x2) {
    // if only Node *x1 is available, we add one statement:
    // Node *x2 = x1->next;
    Node *left;
    for (left = head; left->next != x1; left = left->next) {
        ;
    }

    x1->next = x2->next;
    left->next = x2;
    x2->next = x1;
}
