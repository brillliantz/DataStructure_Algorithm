#include "ch4.0_BinaryTree.h"
#include <string>
#include <iostream>
#include <stack>

bool unary(char c);
bool is_operator(char c);

//    BinaryTree<char> *post_fix_to_tree(std::string s) {
//        BinaryTree<char> *t = new BinaryTree<char>;
//        std::stack<BinaryNode> stk;
//
//        for (char &c : s) {
//            if (is_operator(c)) {
//                BinaryNode *operand_right = stk.top();
//                stk.pop();
//                if (unary(c)) {
//                    BinaryNode *operand_left = nullptr;
//                }
//                else {
//                    BinaryNode *operand_left = stk.top();
//                    stk.pop();
//                }
//                BinaryTree<char> *tree = new BinaryTree<char>(c,
//                        operand_left, operand_right);
//                stk.push(tree);
//            }
//            else {
//                BinaryNode *node = new BinaryNode(c, nullptr, nullptr);
//                stk.push(node);
//            }
//        }
//    }

BinaryTree<char> *post_fix_to_tree(const std::string s) {
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
