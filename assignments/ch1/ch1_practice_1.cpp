#include <iostream>
using namespace std;


void Combinations(int n, int r);
void Combinations_slave(int *arr, int n, int r, int *comb, int current);


int main() {
    int n = 5, r = 3;
    Combinations(n, r);
}

void Combinations(int n, int r) {
    int *arr = new int[n];
    //arr = &arr[0];
    // Initialize the array.
    for (int i = 0; i < n; ++i) {
        arr[i] = i+1;
    }
    int *comb = new int[r+1];
    comb[r] = -1;

    Combinations_slave(arr, n, r, comb, 0);
}

void Combinations_slave(int *arr, int n, int r, int *comb, int current) {
    if (r == 0) {
        for (int *ptr=comb; *ptr!= -1; ++ptr) {
            cout << *ptr;
        }
        cout << endl;
    }
    else {
        for (int i = 0; i < n-r+1; ++i) {
            cout << "i=" << i << " n=" << n << " r=" << r <<" cuurent=" <<current;
            cout << "arr[i] = "<< arr[i] << endl;
            comb[current] = arr[i];
            Combinations_slave(arr+i+1, n-i-1, r-1, comb, current+1);
        }
    }
}
