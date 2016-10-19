#include <iostream>
#include "adt_linkedlist.h"
using namespace std;

int main()
{
    //LinkedList *list = new LinkedList();
    LinkedList mylist;

    cout << "Now the list is empty? " << mylist.empty() << endl;

    mylist.append(15);
    cout << "Now the list is empty? " << mylist.empty() << endl;

    for (int i = 0; i < 8; ++i)
    {
        mylist.append(i);
        cout << "Current size=" << mylist.size() << endl;
        mylist.print();
        cout << endl;
    }


}
