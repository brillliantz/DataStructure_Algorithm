# ch4.1_all 

### README


### 1. (a) Show the result of inserting 3, 1, 4, 6, 9, 2, 5, 7 into an initially empty binary search tree. (b) Show the result of deleting the root.
#### Solution
See `ch4.1_1_a.gv.png` and `ch4.1_1_b.gv.png`.

### 2. 写一递归函数实现在带索引的二叉搜索树( IndexBST) 中查找第 k 个小的元素。
#### solution
If implement as a function outside the class:
```c++
template <typename T>
T k_th_small(const BST<T> &t, int k) {
    if (t.isEmpty()) {
        return 0;
    }
    int p = t.get_leftsize();
    if (p == k) {
        return t.get_rootElment();
    }
    else if (p > k) {
        k_th_small(t.left, k);
    }
    else (p < k) {
        k_th_small(t.right, k - p); 
    }
}
```

If implement as a class method:
```c++
template <typename T>
class BST {
  public:
    T k_th_small(int k) const {
        return k_th_small(root, k);
    }
    
  private:
    T k_th_small(BSTNode *node, int k) {
        if (!node) {
            return 0;
        }
        int p = node->leftsize;
        if (p == k) {
            return node->element;
        }
        else if (p > k) {
            k_th_small(node->left, k);
        }
        else (p < k) {
            k_th_small(node.right, k - p); 
        }
    }
};
```

### 3. 对一棵空的 AVL 树,分别画出插入关键码为 { 16 , 3 , 7 , 11 , 9 , 28 , 18 , 14 , 15} 后的 AVL 树。
#### solution
- See attachment `ch4.1_3.gv` for source code; 
- See attachment `ch4.1_3.gv.1.png` to `ch4.1_3.gv.8.png` for the complete solution. (If you can open `.ps` image, I recommend you open `ch4.1_3.gv.ps` instead of `.pnf` files)


### 4. 设计算法检测一个二叉树是不是一个二叉搜索树 .
#### solution 
```c++
template <typename T>
bool is_BST(const BST<T> &t) {
    // MIN and MAX are minimum and maximum possible value in T type, respectively.
    return is_BST_slave(t, MIN, MAX); 
}

template <typename T>
bool is_BST_slave(const BST<T> &t, const T &lower, const T &upper) {
    if (t.isEmpty()) {
        return true;
    }
    T data = t.get_data();
    if (data > lower && data < upper) {
        return is_BST_slave(t.left, lower, data) && is_BST_slave(t.right, data, upper);
    }
    else {
        return false;
    }
}
```
### 5. 设有序顺序表中的元素依次为 017,094,154,170,275,503,509,512,553,612,677,765,897,908. 试画出 对其进行二分法搜索时的判定树 , 并计算搜索成功的平均搜索长 度。
#### analyis -- the binary search algorithm
```c++
template <typename Comparable>
list<Comparable>::iterator
binary_search(const list<Comparable> &l, const Comparable &x) {
    list<Comparable>::iterator low = std::begin(l), high = std::end(l), mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x == mid) return mid
        else if (x < mid) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}
```
#### solution -- decision tree
see `ch4.1_5.gv.png` for the tree.
#### solution -- average search length
***successful* cases:**
The general formula for a $k$-level BST:
$$
\bar{L} = 2^0 * 1 + 2^1 * 2 + 2^2 * 3 + \dots + 2^{k-1} * k = k * 2^k - 2^k + 1 = (k-1) * 2^k + 1
$$

If there are n nodes, then at most there are $log_2(n)$ levels. So for a linear list with length $n$, the average length of search is:
$$
(log_2(n) - 1) * 2^{log_2(n)} + 1 \sim nlog(n)
$$

$$
\text{ASL} = \frac{1}{n} \sum _{i=1} ^n l_i
=\frac{1}{n} (2^0 * 1 + 2^1 * 2 + 2^2 * 3 + \dots + 2^{h-1} * h)
=\frac{n+1}{n} log_2(n+1) - 1 \approx log_2(n+1) - 1
$$
***unsuccessful* cases:**
[clear explaination](http://stackoverflow.com/questions/24537366/average-complexity-of-binary-search-for-an-unsuccessful-search)

### 6. 在一棵表示有序集 S 的二叉搜索树中 , 任意一条从根到叶结点的路径将 S 分为三部分 : 在该结点左边结点中的元素组成集合 S1; 在该路径上的结点 中的元素组成集合 S2; 在该路径右边结点中的元素组成集合 S3, S=S1US2US3. 若对于任意的 a S1, b S2, c S3, 是否总有 a<=b<=c? 为什 么 ?
#### solution
Yes. Proof:


### 7. 将关键码 DEC, FEB, NOV, OCT, JUL, SEP, AUG, APR, MAR, MAY, JUN, JAN 依次插入到一棵初始为空的 AVL 树中 , 画出每插入一个关键 码后的 AVL 树 , 并标明平衡旋转的类型 .

### *8. 对于一个高度为 h 的 AVL 树 , 其最少结点数是多少 ? 反之 , 对于一个 有 n 个结点的 AVL 树 , 其最大高度是多少 ? 最小高度是多少 ? 

### 9. 分别 delete 50 ,40 in the following 3 阶 B- 树 .

### 10. 分别画出插入 65, 15, 40, 30 后的 3 阶 B- 树。