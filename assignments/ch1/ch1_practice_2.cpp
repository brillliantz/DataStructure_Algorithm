#include <iostream>
using namespace std;

void hanoi(int n, char from, char to, char aux);

int main()
{
	int num_of_disks;
	char from = 'A', to = 'B', aux = 'C';
    cout << "input how many pieces: " << endl;
    cin >> num_of_disks;

    cout << "Assume origin is A, target is B and auxiliary is C, ";
    cout << "then steps are: " << endl;
    hanoi(num_of_disks, from, to, aux);

}

void hanoi(int n, char from, char to, char aux) {
    static int count = 0;
    if (n==1) {
        count += 1;
        cout << count << ". ";
        cout << "move the " << n << "th small disk from ";
        cout << "from " << from <<" to "<< to << endl;
    }
    else {
        hanoi(n-1, from, aux, to);
        count += 1;
        cout << count << ". ";
        cout << "move the " << n << "th small disk from ";
        cout << "from " << from <<" to "<< to << endl;
        hanoi(n-1, aux, to, from);
    }
}
