#include "/home/william/git_repo/DataStructure_Algorithm/ADT/list_impl_ll.h"





void swap(Node *head, Node *x1, Node *x2) {
    // if only Node *x1 is available, we add one statement:
    // Node *x2 = x1->next;
    Node *left = x1->before, *right = x2->next;

    left->next = x2;
    right->before = x1;
    x1->next = right;
    x1->before = x2;
    x2->next = x1;
    x2->before = left;
}
