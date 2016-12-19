/*  test function for assignments T1, T4,
 *  also T2, T3's noSTL implementation.
 */

#include <iostream>
#include "./utils/adt_linkedlist.h"
#include "ch3.0_1_singly.cpp"
#include "ch3.0_1_doubly.cpp"
#include "ch3.0_4.cpp"
#include "ch3.0_2_noSTL.cpp"
#include "ch3.0_3_noSTL.cpp"


template <typename T>
void swap_test(LinkedList<T> mylist, int n);
template <typename T>
void reverse_test(LinkedList<T> mylist);
template <typename T>
void inter_test(LinkedList<T> mylist, LinkedList<T> yourlist);
template <typename T>
void union_test(LinkedList<T> mylist, LinkedList<T> yourlist);
template <typename T>
void PrintNode(Node<T> *head);

int main() {
    LinkedList<int> mylist;
    for (int i = 1; i < 20; i+=2) mylist.push_back(i);

    reverse_test(mylist);
    swap_test(mylist, 2);

    LinkedList<int> yourlist;
    int prime[] = {2, 3, 5, 7, 11, 13, 17, 19};
    for (int i = 0; i < 8; ++i) yourlist.push_back(prime[i]);

    LinkedList<int> l1;
    for (int i = 1; i < 20; i+=2) l1.push_back(i);
    LinkedList<int> l2;
    for (int i = 0; i < 8; ++i) l2.push_back(prime[i]);

    std::cout << "first we print two lists to be merged: " << std::endl;
    mylist.print();
    yourlist.print();

    inter_test(mylist, yourlist);
    union_test(l1, l2);

}

template <typename T>
void union_test(LinkedList<T> mylist, LinkedList<T> yourlist) {
    std::cout << "Now we test the Union function. ";
    Node<T> *merge = Union_noSTL(mylist.begin(), yourlist.begin());
    std::cout << "result: "
        << "(the last 0 is the virtual tail, never mind)" << std::endl;
    PrintNode(merge);
}

template <typename T>
void inter_test(LinkedList<T> mylist, LinkedList<T> yourlist) {
    std::cout << "Now we test the Intersection function. ";
    Node<T> *inter = Intersection_noSTL(mylist.begin(), yourlist.begin());
    std::cout << "result: "
        << "(the last 0 is the virtual tail, never mind)" << std::endl;
    PrintNode(inter);
}

template <typename T>
void swap_test(LinkedList<T> mylist, int n)
{
    std::cout << "------"
        << "function [swap for singly] test." << std::endl;
    std::cout << "swap_test : swap node #"
        << n <<" with node # "<< n+1 << std::endl;
    std::cout << "print prev swap: " << std::endl;
    mylist.print();
    Swap(mylist.head, mylist.at(n));
    std::cout << "print after swap: " << std::endl;
    mylist.print();
    Swap(mylist.head, mylist.at(n)); // swap back
    std::cout << "------"
        << "function [swap for singly] test complete.\n\n" << std::endl;

    std::cout << "------"
        << "function [swap for doubly] test." << std::endl;
    std::cout << "swap_test : swap node #"
        << n <<" with node # "<< n+1 << std::endl;
    std::cout << "print prev swap: " << std::endl;
    mylist.print();
    Swap_doubly(mylist.head, mylist.at(n));
    std::cout << "print after swap: " << std::endl;
    mylist.print();
    Swap_doubly(mylist.head, mylist.at(n)); // swap back
    std::cout << "------"
        << "function [swap for doubly] test complete.\n\n" << std::endl;
}

template <typename T>
void reverse_test(LinkedList<T> mylist)
{
    std::cout << "------"
        << "function [reverse] test." << std::endl;
    std::cout << "print prev reverse: " << std::endl;
    mylist.structure();
    mylist.head = Reverse(mylist.head);
    std::cout << "print after reverse: " << std::endl;
    mylist.structure();
    mylist.head = Reverse(mylist.head); // reverse back
    std::cout << "------"
        << "function [reverse] test complete.\n\n" << std::endl;

}

template <typename T>
void PrintNode(Node<T> *head) {
    Node<T> *ptr = head;
    while (ptr != nullptr) {
        std::cout << ptr->data << ", ";
        ptr = ptr->next;
    }
    std::cout << std::endl;

}
