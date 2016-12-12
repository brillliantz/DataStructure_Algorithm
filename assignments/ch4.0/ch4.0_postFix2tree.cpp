#include "ch4.0_BinaryTree.h" // this class is the same with the one on PPT.
#include <string>
#include <iostream>
#include <stack>

bool unary(char c);
bool is_operator(char c);

//#TODO this is a slow implementation. Use pointer will help.
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
