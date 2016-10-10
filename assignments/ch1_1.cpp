# include<iostream>
using namespace std;

int NumOfOne(int n) {
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else {
        if (n % 2) {
            return 1 + NumOfOne(n/2);
        }
        else {
            return NumOfOne(n/2);
        }
    }
}

int main() {
    int num;
    cout << "input an integer (base 10) :" << endl;
    cin >> num;
    cout << "it contains " << NumOfOne(num) << " 1s." << endl;

    return 0;
}
