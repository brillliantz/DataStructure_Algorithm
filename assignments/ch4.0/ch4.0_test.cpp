#include <iostream>
#include "ch4.0_BinaryTree.h"
#include "ch4.0_postFix2tree.cpp"

int main() {
    // Traversal test:
    BinaryTree<int> bt1 = BinaryTree<int>(), bt2 = BinaryTree<int>();
    BinaryTree<int> tree1;
    tree1.make_tree(15, bt1, bt2);
    BinaryTree<int> tree2(16, bt1, bt2);
    BinaryTree<int> tree3(666, tree1, tree2);
    BinaryTree<int> tree5(333, bt1, bt2);
    BinaryTree<int> tree4(4, tree3, tree5);
    std::cout << "\n\n/*---TEST ONE pre,in and post order traversal---*/"
        << std::endl << "the binary tree to be traversed looks like:"
        << std::endl;
    tree4.pretty_print();
    tree4.pre_order();
    tree4.in_order();
    tree4.post_order();

    // post_fix_expression to expression tree test:
    std::string s1 = "ab+c-de*f@*+";
    std::cout << "\n\n/*---TEST TWO post fix expression to expression tree---*/"
        << std::endl << "test postFix expression(@ stands for unary an operator): "
        << s1 << std::endl;
    BinaryTree<char> expt = post_fix_to_tree(s1);
    expt.pre_order();
    expt.pretty_print();

    return 0;
}
