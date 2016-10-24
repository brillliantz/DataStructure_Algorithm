/*  Implement Josephus(n, m) using circular linked list
 *  the circular linked list is implemented based on stl::list
 */

#include <iostream>
#include <list>
using namespace std;

template<typename T>
void PrintList(list<T> *mylist)
{
    for (auto iter = mylist->begin(); iter != mylist->end(); ++iter)
    {
        cout << *iter << ", ";
    }
    cout << endl;
}
int Joseph(int n, int m);

int main()
{
    int n, m;
    cout << "input n, m, respectively: " << endl;
    cin >> n >> m;
    cout << "The winner is: #" << Joseph(n, m) << endl;
}

int Joseph(int n, int m)
{
    list<int> *circle = new list<int>(n);
    int i = 1;
    for (auto iter = circle->begin(); iter != circle->end(); ++iter)
    {
        *iter = i;
        ++i;
    }

    auto iter = circle->begin();
    --m;

    while (circle->size() != 1)
    {
        for (int i = 1; i <= m; ++i)
        {
            cout << "#" << *iter << " is passed by." << endl;
            ++iter;
            if (iter == circle->end())
            {
                iter = circle->begin();
            }
        }
        cout << "#" << *iter << " is out." << endl;
        iter = circle->erase(iter);
        if (iter == circle->end())
        {
            iter = circle->begin();
        }
        cout << "current circle size: " << circle->size() << endl << endl;
    }
    return *iter;
}
