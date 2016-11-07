#include<iostream>
#include<stack>
#include <string>
using std::string;
using namespace std;

int Precedence(char ch);
string Infix2Postfix(string infix);

int main() {
    string infix2("m*(n/p*q-d*(g+x)+y)/z");
    string postfix = Infix2Postfix(infix2);
    cout << "\nInfix expression:    " << infix2;
    cout << "\nPostfix expression:    " << postfix;
    cout << endl;

    return 0;
}

int Precedence(char ch) {
    switch (ch) {
        case '/':
        case '*': return 2;
        case '+':
        case '-': return 1;
        default : return 0;
    }
}

string Infix2Postfix(string infix) {
    int size = infix.size();
    string postfix(size, '0');

    int weight, i = 0, k = 0;

    char ch;
    stack<char> s;
    while (i < size) {
        ch = infix[i];

        switch (ch) {
            case ')':
                while (!s.empty() && s.top() != '(') {
                   postfix[k++] = s.top();
                   s.pop();

                }
                if (!s.empty()) {
                   s.pop();
                }
                i++;
                continue;
            case '(':
                s.push(ch);
                i++;
                continue;
            default:
                ;
        }

        weight = Precedence(ch);
        if (weight == 0) {
           postfix[k++] = ch;
        }
        else {
           if (s.empty()) {
              s.push(ch);
           }
           else {
              while (!s.empty() && s.top() != '(' &&
                    weight <= Precedence(s.top())) {
                 postfix[k++] = s.top();
                 s.pop();
              }
              s.push(ch);
           }
        }
        i++;
    }
    while (!s.empty()) {
        postfix[k++] = s.top();
        s.pop();
    }
    while (k < size) {
        postfix[k++] = '\0';
    }
    return postfix;
}

