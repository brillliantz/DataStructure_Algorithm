#include <iostream>
using namespace std;


int main() {
    char c[5] = "what";
    char *p = &c[0];
    for (int i = 0; i < 5; ++i) {
        cout << char(p[i] - ('a' - 'A')) << endl;
    }
    cout << *p << endl;

    return 0;
}
