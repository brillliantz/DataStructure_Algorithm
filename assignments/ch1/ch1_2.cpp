#include <iostream>
using namespace std;

void permute_master(char *s);
void permute_slave(char *s, int low, int high);
void swap(char* s, int i, int j);

int main() {
    char c[5] = "what";
    permute_master(&c[0]);

    return 0;
}

void permute_master(char *s) {
    char *ptr = s;
    int len = 0;
    while (*ptr) {
        ++len;
        ++ptr;
    }
    permute_slave(s, 0, len-1);
}

void permute_slave(char *s, int low, int high) {
    int current;
    if (low == high) {
        char *p = s;
        while (*p) {
            cout << *p;
            ++p;
        }
        cout << endl;

    }
    else {
        for (current = low; current <= high; ++current) {
            swap(s, low, current);
            permute_slave(s, low+1, high);
            swap(s, low, current);
        }
    }
}

void swap(char* s, int i, int j) {
    int tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
}
