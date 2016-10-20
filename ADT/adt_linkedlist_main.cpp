#include <iostream>
#include "adt_linkedlist.h"
#include "../assignments/ch3.0_1_singly.cpp"
#include "../assignments/ch3.0_4.cpp"
using namespace std;

void empty_test();
void append_test(LinkedList *mylist);
void swap_test(LinkedList *mylist, int n);
void at_test(LinkedList *mylist);
void reverse_test(LinkedList *mylist);


int main()
{
    LinkedList *mylist = new LinkedList;

    append_test(mylist);
    //at_test(mylist);

    reverse_test(mylist);
    //swap_test(mylist, 2);
    //swap_test(mylist, 0);
}

void reverse_test(LinkedList *mylist)
{
    cout << "reverse_test : " << endl;
    cout << "structure before reverse: " << endl;
    mylist->structure();
    mylist->head = Reverse(mylist->head);
    cout << "structure after reverse: " << endl;
    mylist->structure();

}
void append_test(LinkedList *mylist)
{
    for (int i = 2; i < 129; i *= 2)
    {
        mylist->append(i);
        //cout << "Current size=" << mylist->size() << endl;
        //mylist->print();
        //cout << endl;
    }
}

void at_test(LinkedList *mylist)
{
    cout << "address of node #3 is " << mylist->at(3) << endl;
    cout << "address of node #2 is " << mylist->at(2) << endl;
}

void swap_test(LinkedList *mylist, int n)
{
    Node *p = mylist->at(n);
    cout << "swap_test : swap node #" << n <<" with node # "<< n+1 << endl;
    cout << "structure before swap: " << endl;
    mylist->structure();
    Swap(mylist->head, p);
    cout << "structure after swap: " << endl;
    mylist->structure();
}

void empty_test()
{
    LinkedList *mylist = new LinkedList;
    cout << "Now the list is empty? " << mylist->empty() << endl;
    mylist->append(15);
    cout << "Now the list is empty? " << mylist->empty() << endl;
}
