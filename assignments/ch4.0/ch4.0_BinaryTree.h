#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

#include <utility>
#include <iostream>

template <typename T>
class BinaryTree {
  public:
    BinaryTree() {root = nullptr;}
    BinaryTree(const T &d, BinaryTree<T> &lt, BinaryTree<T> &rt)
    {
        root = new BinaryNode(d, lt.root, rt.root);
    }

    bool is_empty() const {return (!root);}
    void make_tree(const T &d, BinaryTree<T> &lt, BinaryTree<T> &rt)
    {
        root = new BinaryNode(d, lt.root, rt.root);
    }
    void break_tree(T &d, BinaryTree<T> &lt, BinaryTree<T> &rt) {
        d = root.data;
        lt.root = root.left;
        rt.root = root.right;
        delete root;
        root = nullptr;
    }
    void pre_order() const {
        std::cout << "\n====pre_order traversal: " << std::endl;
        pre_order(root);
        std::cout << "\n====pre_order traversal complete." << std::endl;
    }


  private:
    struct BinaryNode {
        T data;
        BinaryNode *left;
        BinaryNode *right;

        BinaryNode(const T &d, BinaryNode *lt = nullptr,
                   BinaryNode *rt = nullptr) :
            data{d}, left{lt}, right{rt}
        {}
        BinaryNode(const T &&d, BinaryNode *lt = nullptr,
                   BinaryNode *rt = nullptr) :
            data{std::move(d)}, left{lt}, right{rt}
        {}
    };
    BinaryNode *root;

    void pre_order(BinaryNode *node) const {
        if (!node) {
            std::cout << "nullptr" << ", ";
        }
        else {
            std::cout << node->data << ", ";
            pre_order(node->left);
            pre_order(node->right);
        }
    }

/**
 * Extra method functions that are not indispensable for the class:
 */
  public:
    int num_of_leaf() const {
        return num_of_leaf(this->root);
    }
    void exchange() {
        exchange(this->root);
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
    void exchange(BinaryNode *t) {
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
/**
 * friend function declaration for functions outside this class:
 */
};

#endif
