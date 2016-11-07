# Ch3.1_all

## 1. 2009年考研统考题 1)
为解决计算机主机与打印机之间速度不匹配问题, 通常设置一个打印数据缓冲区,主机将要输出的数据依次写入该缓冲区, 而打印机则依次从该缓冲区中取出数据. 该缓冲区的逻辑结构应该是  
A. 栈
B. 队列
C. 树
D. 图

#### Solution
Things waiting to be printed are **IN ORDER**. Those first get into the buffer should also get out (be printed) first. Therefore, we should use **QUEUE**.  
B.

## 1. 2009年考研统考题 2)
设栈S和队列Q 的初始状态为空, 元素 a,b,c,d,e,f,g 依次进入栈S. 若每个元素出栈后立即进入队列Q, 且7个元素出队的顺序是 b,d,c,f,e,a,g , 则栈S的容量至少是  
A. 1
B. 2
C. 3
D. 4

#### Solution
The status of the stack:  
```
a
a, b
a
a, c
a, c, d
a, c
a
a, e
a, e, f
a, e
a
(empty)
g
```
The maximum number of elements in the stack is **3**.  
C.

## 2. 
Suppose that a singly list is implemented with both a header and tail node. Describe contant-time algorithms to  
a. Insert item x before position p ( given by an iterator ).
b. Remove the item stored at position p ( given by an iterator )

#### Solution

```c++
template<Typename T>
void LinkedList<T>::insert(T x, iterator &p) {
    Node *prev = begin(this).current;
    Node *cur = p.current; // itr.current is the pointer stored by the iterator
    while (prev->next != cur) {
        prev = prev->next;
    }
    prev->next = new Node(x, prev, cur); // using Node's construction function, 
                                         // prototype: Node(T x, Node *prev, Node *next);
}

template<Typename T>
void LinkedList<T>::remove(iterator &p) {
    Node *prev = begin(this).current;
    Node *cur = p.current; // itr.current is the pointer stored by the iterator
    while (prev->next != cur) {
        prev = prev->next;
    }
    prev->next = cur.next;
    delete cur;
}
  
```

## 3.
假设以数组Q[m]存放循环队列中的元素,同时以rear和length 分别指示环形队列中的队尾位置和队列中所含元素的个数:
1)求队列中第一个元素的实际位置。
2)给出该循环队列的队空条件和队满条件,并写出相应的插入(enqueue)和删除(dlqueue)元素的操作算法。

#### Solution
1)
```c++
int FrontNum(int rear, int length) {
    return (rear < length)?(rear - length + m):(rear - length);
}
```

2)
```c++
template <typename T>
bool QueueAr<T>::empty(int rear, int length) {
    return (length == 0);
}

template <typename T>
bool QueueAr<T>::full(int rear, int length) {
    return (!empty());
}

template <typename T>
void QueueAr<T>::enqueue(T x) {
    if (full()) return 0;    // do nothing if already full
    else {
        rear = increment(rear);    // increase the rear using increament function
        theArr[rear] = x;    // copy the new object into array
        ++length;
    }
}

template <typename T>
void QueueAr<T>::dequeue() {
    if (empty()) return 0;
    else {
        T res = theArr[front];    // copy the object at front
        front = increment(front);    // change the front marker
        --length;
    }
    return res;    // return the object at front
}
```

