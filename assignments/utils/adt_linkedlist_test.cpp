#include <iostream>
#include "adt_linkedlist.h"
#include "../assignments/ch3.0_1_singly.cpp"
#include "../assignments/ch3.0_4.cpp"
#include "../assignments/ch3.0_3_noSTL.cpp"

using namespace std;

void empty_test();
void push_test(LinkedList *mylist, unsigned int n);
void at_test(LinkedList *mylist);

int main()
{
    LinkedList *mylist = new LinkedList;

    empty_test();

    push_test(mylist, 2);
    //at_test(mylist);

}

void push_test(LinkedList *mylist, unsigned int n)
{
    std::cout << "------"
        << "member function [push_front] test" << std::endl;
    std::cout << "before push_front: " << std::endl;
    mylist->print();
    for (int i = n; i < 400; i *= n)
    {
        //cout << "Current size=" << mylist->size() << endl;
        //mylist->print();
        //cout << endl;
        mylist->push_front(i);
    }
    std::cout << "after push_front: " << std::endl;
    mylist->print();
    std::cout << "------"
        << "member function [push_front] test complete.\n\n" << std::endl;
}

//void at_test(LinkedList *mylist)
//{
//    cout << "address of node #3 is " << mylist->at(3) << endl;
//    cout << "address of node #2 is " << mylist->at(2) << endl;
//}

void empty_test()
{
    std::cout << "------"
        << "member function [emtpy] test" << std::endl;
    std::cout << "first create a new LinkedList. " << std::endl;
    LinkedList *mylist = new LinkedList;
    cout << "Now the list is empty? " << mylist->empty() << endl;
    std::cout << "then insert one element. " << std::endl;
    mylist->push_front(15);
    cout << "Now the list is empty? " << mylist->empty() << endl;
    std::cout << "------"
        << "member function [emtpy] test complete.\n\n" << std::endl;
}


