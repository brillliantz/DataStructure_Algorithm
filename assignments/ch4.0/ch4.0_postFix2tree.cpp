#include <string>
#include <iostream>
#include <stack>
#include "./BinaryTree.h"

int main() {
    return 0;
}

bool is_operator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/') {
        return true;
    }
    else {
        return false;
    }
}

bool unary(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/') {
        return false;
    }
    else {
        return true;
    }

}

BinaryTree<char> *post_fix_to_tree(std::string s) {
    BinaryTree<char> *t = new BinaryTree<char>;
    std::stack<BinaryNode<char>> sk;

    for (char &c : s) {
        if (is_operator(c)) {
            BinaryNode<char> *operand_right = sk.top();
            sk.pop();
            if (unary(c)) {
                BinaryNode<char> *operand_left = nullptr;
            }
            else {
                BinaryNode<char> *operand_left = sk.top();
                sk.pop();
            }
            BinaryTree<char> *tree = new BinaryTree<char>(c, operand_left, operand_right);
            sk.push(tree);
        }
        else {
            BinaryNode<char> *node = new BinaryNode<char>(c, nullptr, nullptr);
            sk.push(node);
        }
    }

}
