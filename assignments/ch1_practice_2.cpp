#include <iostream>
using namespace std;

void hanoi(int n,char x,char y)
{
	if (n==1)
	cout <<x<<"->"<<y<<endl;
	else
	{
		char z;
		switch ((int)(x+y))
		{
			case 65+66:
				z=67;
				break;
			case 66+67:
				z=65;
				break;
			case 65+67:
				z=66;
				break;
		}

		hanoi(n-1,x,z);
		cout <<x<<"->"<<y<<endl;
		hanoi(n-1,z,y);
	}
}
int main()
{
	int n;
	char x,y;
    cout << "input how many pieces: " << endl;
    cin >> n;
    cout << "Assume origin is A and target is B, then steps are: " << endl;
    x = 'A';
    y = 'B';
	hanoi(n,x,y);

}
