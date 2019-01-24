#include <iostream>
using namespace std;

int f(int n) {  
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	int f0 = 1;
	int f1 = 2;
	int f2 = 0;

	for (int i = 2; i < n; i++) {
		f2 = (f0 + f1)%10;
		f0 = f1;
		f1 = f2;
	}
	return f2;
}
int main()
{
	int t;
	cin >> t;
	int n;
	while (t--)
	{
		cin >> n;
		cout << f(n) << endl;
	}
}