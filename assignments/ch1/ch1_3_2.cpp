#include <iostream>
using namespace std;


double AveOfArr(int *a, int n);

int main() {
    int arr[8] = {3, 6, 9, 1, 4, 2, 9, 7};
    cout << "the average is: "<< AveOfArr(&arr[0], 8) << endl;

    return 0;
}

double AveOfArr(int *a, int n) {
    if (n == 1) return *a;
    else {
        return (double)(*a * 1 + AveOfArr(a+1, n-1) * (n-1)) / n;
    }
}
