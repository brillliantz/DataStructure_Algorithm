#include <iostream>
#include <list>
#include "ch3.0_2.cpp"
#include "ch3.0_3.cpp"
using namespace std;

template<typename T>
void PrintList(list<T> *mylist);


int main()
{
    list<int> *mylist1 = new list<int>{2,4,8,16,32,64,128};
    list<int> *mylist2 = new list<int>{1,2,4,5,9,13,44,99,128,131};

    cout << "origin" << endl;
    PrintList(mylist1);
    PrintList(mylist2);

    cout << "Intersection: " << endl;
    PrintList(Intersection(mylist1, mylist2));

    cout << "Union: " << endl;
    PrintList(Union(mylist1, mylist2));

    return 0;

}

template<typename T>
void PrintList(list<T> *mylist)
{
    for (auto iter = mylist->begin(); iter != mylist->end(); ++iter)
    {
        cout << *iter << ", ";
    }
    cout << endl;
}
