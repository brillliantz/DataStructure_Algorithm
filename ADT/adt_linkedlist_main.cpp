#include <iostream>
#include <iomanip>
#include "adt_linkedlist.h"
using namespace std;

int main()
{
    LinkedList *list = new LinkedList();

    for (int i = 0; i < 8; ++i)
    {
        list->append(i);
        cout << "current status: size=" << list->size() << endl;
        list->print();
        cout << endl;
    }


}
