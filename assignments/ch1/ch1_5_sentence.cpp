#include <iostream>
using namespace std;

bool IsPalindrom_slave(char *h, char *t);
bool IsPalindrom_master(char* s);

int main() {
    char arr[] = "Madam, I'm Adam.";
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

    int len = tail - head + 1;

    char *clean_head = new char[len];
    char *pc = clean_head;
    for (char *ptr = head; ptr <= tail; ++ptr) {
        if ((*ptr >='A' && *ptr <= 'Z') || (*ptr >= 'a' && *ptr <= 'z')) {
            if (*ptr >= 'A' && *ptr <= 'Z') {
                *pc = (char)(*ptr + 'a' - 'A');
            }
            else *pc = *ptr;
            ++pc;
        }
    }
    pc -= 1;

    return IsPalindrom_slave(clean_head, pc);

}

bool IsPalindrom_slave(char *h, char *t) {
    if (h >= t) return true;
    else {
        return ((*h == *t) && (IsPalindrom_slave(h+1, t-1)));
    }
}
