#include <iostream>
#include "adt_linkedlist.h"
//#include "adt_linkedlist.cpp"

using namespace std;

template <typename T>
void empty_test(T dummy);

template <typename T>
void push_test(LinkedList<T> *mylist, unsigned int n);

template <typename T>
void at_test(LinkedList<T> *mylist);

int main()
{
    LinkedList<int> *mylist = new LinkedList<int>;

    empty_test(0);

    push_test(mylist, 2);
    //at_test(mylist);

}

template <typename T>
void push_test(LinkedList<T> *mylist, unsigned int n)
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

//template <typename T>
//void at_test(LinkedList<int> *mylist)
//{
//    cout << "address of node #3 is " << mylist->at(3) << endl;
//    cout << "address of node #2 is " << mylist->at(2) << endl;
//}

template <typename T>
void empty_test(T dummy)
{
    std::cout << "------"
        << "member function [emtpy] test" << std::endl;
    std::cout << "first create a new LinkedList<int>. " << std::endl;
    LinkedList<T> *mylist = new LinkedList<T>;
    cout << "Now the list is empty? " << mylist->empty() << endl;
    std::cout << "then insert one element. " << std::endl;
    mylist->push_front(15);
    cout << "Now the list is empty? " << mylist->empty() << endl;
    std::cout << "------"
        << "member function [emtpy] test complete.\n\n" << std::endl;
}


