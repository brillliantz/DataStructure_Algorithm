/*  return the intersection of
 *  two sorted singly linked list.
 *  using stl::list
*/
#include <list>
using namespace std;

template<typename T>
list<T> *Intersection(list<T> *l1, list<T> *l2)
{
    auto iter1 = l1->begin();
    auto iter2 = l2->begin();

    list<T> *mylist = new list<T>;
    while (iter1 != l1->end() && iter2 != l2->end())
    {
        if (*iter1 < *iter2)
        {
            ++iter1;
        }
        else if (*iter1 > *iter2)
        {
            ++iter2;
        }
        else
        {
            mylist->push_back(*iter1);
            ++iter1;
            ++iter2;
        }
    }
    return mylist;
}
