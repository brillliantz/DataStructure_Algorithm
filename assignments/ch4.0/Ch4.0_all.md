# Ch4.0_all 

### README
In this folder:
1. `.gv`, `.ps` and `.png` files are images of trees that are used in my assignment.
2. `.h` and `cpp` files are implementations of algorithms / functions used in my assignment. To test them, just: `make`, then `./ch4.0_test`.


### 1. 给出如下各表达式的二叉树
1. (a+b)/(c-d*e)+e+g*h/a
2. -x-y*z+(a+b+c/d*e)
3. ((a+b)>(c-d))|| a<f &&(x<y || y>z)

#### solution
I use *GraphViz* to draw the binary trees. See the following for source code. See attachments for iamge files.

1.
```
digraph G {
    p2 [label="+"]
    e2 [label="e"]
    p2 -> "/", e2;
    "+" -> a, b;
    "/" -> "+", "-";
    "-" -> c, "*";
    "*" -> d, e;
    p3 [label="+"]
    d2 [label="/"]
    m2 [label="*"]
    a2 [label="a"]
    p3 -> p2, d2;
    d2 -> m2, a2;
    m2 -> g, h;
}
```
Corresponding **attachment**: `ch4.0_1_1.gv`

2.
```
digraph G {
    plus1 [label = "+"]
    plus2 [label = "+"]
    plus3 [label = "+"]
    minus1 [label = "-"]
    minus2 [label = "-"]
    mul1 [label = "*"]
    mul2 [label = "*"]
    div1 [label = "/"]
    minus2 -> minus1, mul1;
    minus1 -> x;
    mul1 -> y, z;
    plus1 -> minus2, plus2;
    plus2 -> a, plus3;
    plus3 -> b, div1;
    div1 -> c, mul2;
    mul2 -> d, e;
}
```
Corresponding **attachment**: `ch4.0_1_2.gv`

3.
```
digraph G {
    grt1, grt2 [label = ">"]
    ls1, ls2 [label = "<"]
    or1, or2 [label = "||"]
    and1 [label = "&&"]
    plus1 [label = "+"]
    minus1 [label = "-"]
    or1 -> grt1, ls1;
    grt1 -> plus1, minus1;
    a1, a2 [label = "a"]
    plus1 -> a1, b;
    minus1 -> c, d;
    ls1 -> a2, f;
    and1 -> or1, or2;
    or2 -> ls2, grt2;
    y1, y2 [label = "y"]
    ls2 -> x, y1;
    grt2 -> y2, z;
}
```
Corresponding **attachment**: `ch4.0_1_3.gv`

### 2. 如果一棵树有$n\_1$ 个度为$1$的结点,有$n\_2$个度为$2$的结点, ..., $n_m$ 个度为$m$的结点,试问有多少个度为$0$的结点? 写出推导过程.

#### solution
let $n$ be the total number of nodes, $n_0$ be the number of nodes whose degree are $0$, then we have the relationship:
$$
n = \sum_{i=0}^{m} n_i.
$$

For every node, it can only have $1$ parent, so nodes that belong to diffrent parents are different. Let
$$
A = \sum_{i=1}^{m} i*n_i,
$$
then $A$ is the number of all nodes who have parents, so 
$$
A = n - 1.
$$

Combine formulas above, we have:
$$
n_0 = n - \sum_{i=1}^{m} n_i
= \sum_{i=1}^{m} i*n_i - \sum_{i=1}^{m} n_i
= \sum_{i=1}^{m} (i-1)*n_i
= \sum_{i=2}^{m} (i-1)*n_i
$$

### 3. 分别找出满足以下条件的所有二叉树
1. 二叉树的前序序列与中序序列相同
2. 二叉树的中序序列与后序序列相同
3. 二叉树的前序序列与后序序列相同

#### solution note
I use set notation in the following solutions. And I **assume that duplicate elements are not allowed in the tree**, or the questions will be too difficult to solve.

#### solution to 1.
From the description, we konw:  
`visit(root) + preOrder(left) + preOrder(right)` is equal to `inOrder(left) + visit(root) + inOrder(right)`.

Since the number of nodes visited is the same no matter which order we choose, we have:  
`visit(root) + preOrder(left) = inOrder(left) + visit(root)` and `preOrder(right) == inOrder(right)`.

Therefore, the right subtree should have the same property with the root. We only need to deal with:  
`visit(root) + preOrder(left) = inOrder(left) + visit(root)`.

Because the elements in the left subtree are different from that contained by the root, the only possibility is that **the left subtree is empty**.

**The answer is:** For every node in the tree, its left subtree is empty.

#### solution to 2.
This question is sysmetrical to question 1.  
So **The answer is:** For every node in the tree, its right subtree is empty.

#### solution to 3.
From the description, we konw:  
`visit(root) + preOrder(left) + preOrder(right)` is equal to `postOrder(left) + postOrder(right) + visit(root)`.

Because the elements in the left subtree and right subtree are different from that contained by the root, the only possibility is that **both subtrees are empty**.

**The answer is:** The tree has only one node (root) or is empty.

#### what if duplicate elements are allowed?
The problem will become quite complicated because there will be many kinds of trees that satisfy the description. For example see **attachment**: `ch4.0_3_duplicate.png`. Souce code is as following:
```
digraph G {
    a1, a2, a3 [label = "1"]
    a1 -> 5, 2;
    5 -> a2, a3;
    b1, b2, b3, b4, b5 [label = "1"]
    c1, c2, c3 [label = "2"]
    d1, d2 [label = "3"]
    null1, null2 [label = "null"]
    b1 -> b2, c1;
    b2 -> b3, b4;
    b4 -> null1, b5;
    c1 -> c2, d1;
    c2 -> null2, c3;
    d1 -> d2, "^";
}
```

### 4. 若用二叉链表作为二叉树的存储表示,试对以下问题编写递归算法。
1. 统计二叉树中叶结点的个数。
2. 以二叉树为参数,交换每个结点的左子女和右子女

**NOTE:** I have implemented these two algorithms in the file `ch4.0_BinaryTree.h`. I also write tests in the file `ch4.0_test.cpp`. 

#### solution to 1.
```c++
template <typename T>
class BinaryTree {
/** 
 * here we do not implement other methods.
 */
  public:
    int num_of_leaf() const {
        return num_of_leaf(this->root);
    }
  private:
    int num_of_leaf(BinaryNode *t) const {
        if (!(t->left || t->right)) {
            return 1;
        }
        else {
            return num_of_leaf(t->left) + num_of_leaf(t->right);
        }
    }
}
```

#### solution to 2.
```c++
template <typename T>
class BinaryTree {
/** 
 * here we do not implement other methods.
 */
  public:
    void exchange() {
        return exchange(this->root);
    }
  private:
    void exchange(BinaryNode * t) {
        BinaryNode *tmp = t->left;
        t->left = t->right;
        t->right = tmp;
        
        if (t->left) {
            exchange(t->left);
        }
        if (t->right) {
            exchange(t->right);
        }
    }
}
```


### 5. 已知一棵二叉树的先序遍列结果是 ABECDFGHIJ, 中序遍列结果是 EBCDAFHIGJ, 试画出这棵二叉树。
#### algorithm description
1. find root (the first in the sequence);
2. split elements in left subtree (to the left of root, in inOrder sequence) and right subtree (to the right of root, in inOrder sequence);
3. apply step 1 and 2 to the left subtree and right subtree, respectively.

#### solution
##### analysis
```
A -> BECD, FGHIJ;
B -> E, CD;
F -> ^, GHIJ;
C -> ^, D;
G -> HI, J;
H -> ^, I;
```
##### answer
See **attachment** `ch4.0_5.gv`. The source code is as following:
```
digraph G {
    null1, null2, null3 [label = "null"]
    A -> B, F;
    B -> E, C;
    F -> null1, G;
    C -> null2, D;
    G -> H, J;
    H -> null3, I;
}
```

### 6. 编写一个Java函数, 输入后缀表达式, 构造其二叉树表示。设每个操作符有一个或两个操作数。

**NOTE:** I have implemented this algorithm in the file `ch4.0_postFix2Tree.cpp`. I also write tests in the file `ch4.0_test.cpp`. 

```c++
#include "ch4.0_BinaryTree.h" // this class is the same with the one on PPT.
#include <string>
#include <iostream>
#include <stack>

bool unary(char c);
bool is_operator(char c);

BinaryTree<char> post_fix_to_tree(const std::string s) {
    BinaryTree<char> tree, operand_left, operand_right;
    std::stack<BinaryTree<char>> stk;

    for (const char &c : s) {
        if (is_operator(c)) {
            operand_right = stk.top();
            stk.pop();
            if (unary(c)) {
                operand_left = BinaryTree<char>();
            }
            else {
                operand_left = stk.top();
                stk.pop();
            }
            tree = BinaryTree<char>(c, operand_left, operand_right);
            stk.push(tree);
        }
        else {
            BinaryTree<char> dummy1 = BinaryTree<char>(), dummy2 = BinaryTree<char>();
            tree = BinaryTree<char>(c, dummy1, dummy2);
            stk.push(tree);
        }
    }
    return stk.top();
}

bool is_operator(char c) {
    // here '@' is the symbol of an unary operator.
    if (c == '+' || c == '-' || c == '*' || c == '/'
            || c == '@') {
        return true;
    }
    else {
        return false;
    }
}

bool unary(char c) {
    //here we assume that only +-*/ are binary operators.
    if (c == '+' || c == '-' || c == '*' || c == '/') {
        return false;
    }
    else {
        return true;
    }
}
```

### 7. 给定权值{ 15, 03, 14, 02, 06, 09, 16, 17 }, 构造相应的霍夫曼树,并计算它的带权外路径长度。

#### Solution part 1 - construction of huffman tree
- See attachment `ch4.7.gv` for source code; 
- See attachment `ch4.7.gv.1.png` to `ch4.7.gv.8.png` for the complete solution. (If you can open `.ps` image, I recommend you use that instead of `.pnf` files)

#### Solution part 2 - calculation of weighted path length
According to our result, we have:
$$
\text{WPL} = (16 + 17) * 2 + (9 + 14 + 15) * 3 + (6 + 2 + 3) * 4 = 224
$$


### 8. c1, c2, c3, c4, c5, c6, c7, c8这八个字母的出现频率分别{5,25,3,6,10,11,36,4,}, 为这八个字母设计不等长的Huffman编码, 并给出该电文的总码数.

#### Solution part 1 - construction of huffman tree
- See attachment `ch4.8.gv` for source code; 
- See attachment `ch4.8.gv.1.png` to `ch4.7.gv.8.png` for the complete solution. (If you can open `.ps` image, I recommend you use that instead of `.pnf` files)

#### Solution part 2 - calculation of weighted path length
According to our result, we have:
$$
\text{WPL} = (25 + 36) * 2 + (10 + 11) * 3 + (3 + 4 + 5 + 6) * 4 = 257
$$
