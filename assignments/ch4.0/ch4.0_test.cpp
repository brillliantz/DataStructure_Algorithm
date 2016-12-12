#include <iostream>
#include "ch4.0_BinaryTree.h"
#include "ch4.0_postFix2tree.cpp"

int main() {
    std::cout << "Start at main() func." << std::endl;
    BinaryTree<int> bt1 = BinaryTree<int>(), bt2 = BinaryTree<int>();
    BinaryTree<int> tree1;
    tree1.make_tree(15, bt1, bt2);
    BinaryTree<int> tree2(16, bt1, bt2);
    BinaryTree<int> tree3(666, tree1, tree2);
    //tree.structure();
    tree3.pre_order();

    BinaryTree<char> c1 = BinaryTree<char>(), c2 = BinaryTree<char>();
    BinaryTree<char> c4('a', c1, c2), c5('b', c1, c2), c3('+', c4, c5);
    c3.pre_order();

    std::string s1 = "ab+c-d*";
    BinaryTree<char> *expt = post_fix_to_tree(s1);
    expt->pre_order();

    std::cout << "All done in main() func." << std::endl;
}
