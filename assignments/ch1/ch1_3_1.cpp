#include <iostream>
using namespace std;


int MaxInArr(int *a, int n);

int main() {
    int arr[8] = {3, 5, 9, 1, 4, 2, 0, 7};
    cout << "the maximum is: "<< MaxInArr(&arr[0], 8) << endl;

    return 0;
}

int MaxInArr(int *a, int n) {
    if (n == 1) return *a;
    else {
        int b = MaxInArr(a+1, n-1);
        return (*a > b)?(*a):b;
    }
}
