#include <iostream>
using namespace std;

bool IsPalindrom_slave(char *h, char *t);
bool IsPalindrom_master(char* s);

int main() {
    char arr[] = "wabcnyncbaw";
    if (IsPalindrom_master(&arr[0])) {
        cout << "yes" << endl;
    }
    else cout << "no" << endl;
}

bool IsPalindrom_master(char* s) {
    char *head = s;
    char *tail = s;
    while (*(tail+1)) {
        ++tail;
    }
    return IsPalindrom_slave(head, tail);

}

bool IsPalindrom_slave(char *h, char *t) {
    if (h <= t) return true;
    else {
        if (*h != *t) return false;
        else return IsPalindrom_slave(h+1, t-1);
    }
}
