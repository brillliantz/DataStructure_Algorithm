/*  Implement Josephus(n, m) using circular linked list
 *  the circular linked list is implemented by myself
 */

#include <iostream>
using namespace std;

template<typename T>
class Node
{
    public:
        T data;
        Node *next;
        Node *before;

    public:
        Node(T value) :
            data{value}, next{nullptr}, before{nullptr}
        { }
};

template<typename T>
class LinkedList
{
    public:
        Node<T> *head;
        Node<T> *tail;
        int length;

    public:
        LinkedList() :
            head{nullptr}, tail{nullptr}, length{0}
        { }
        int size() const
        {
            return this->length;
        }
        void push_front(T value)
        {
            if (!(this->head))
            {
                Node<T> *node = new Node<T>(value);
                this->head = node;
                this->tail = node;
            }
            else
            {
                Node<T> *node = new Node<T>(value);
                node->next = this->head;
                this->head->before = node;
                this->head = node;
            }
            ++this->length;
        }

        Node<T> *erase(Node<T> *pos)
        {
            pos->before->next = pos->next;
            pos->next->before = pos->before;
            Node<T> *res = pos->next;
            delete pos;
            --this->length;
            return res;
        }


};

template <typename T>
void structure(LinkedList<T> *mylist)
{
    cout << "======Now printing the structure of the LinkedList"
         << ", structure format is #. data@[address]" << endl;

    int count = 0;
    for (Node<T> *p = mylist->head; p != nullptr; p = p->next)
    {
        cout << count << ". " << p->data << "@[" << p << "] --> ";
        if (count % 7 == 6) cout << endl;
        ++count;
    }
    cout << "nullptr" << endl << endl;
}

int Joseph(int n, int m);

int main()
{
    int n, m;
    cout << "input n, m, respectively: " << endl;
    cin >> n >> m;
    cout << "The winner is: #" << Joseph(n, m) << endl;
}

/**
 *  using circluar doubly linked list to
 *  implement Joseph Circle problem
 */
int Joseph(int n, int m)
{
    LinkedList<int> *circle = new LinkedList<int>;

    for(int i = n; i > 0; --i)
    {
        circle->push_front(i);
    }

    structure(circle);
    circle->tail->next = circle->head;
    circle->head->before = circle->tail;

    Node<int> *sword = circle->head;
    --m;
    while (circle->size() != 1)
    {
        for (int i = 1; i <= m; ++i)
        {
            cout << "#" << sword->data << " is passed by." << endl;
            sword = sword->next;
        }
        cout << "#" << sword->data << " is out." << endl;
        sword = circle->erase(sword);
        cout << "current circle size: " << circle->size() << endl << endl;
    }
    return sword->data;
}

