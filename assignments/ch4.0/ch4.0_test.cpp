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
    std::cout << "All done in main() func." << std::endl;
}
