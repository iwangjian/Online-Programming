#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n, d;
	while (cin >> n>>d)
	{
		int digits[30];
		int t = 0;
		if (n == 0)
		{
			cout << "Yes" << endl << 0 << endl;
			break;
		}
		while (n >0)
		{
			digits[t] = n%d;
			t++;
			n = n / d;
		}
		t = t - 1;
		int i = 0;
		for (;i <= t;i++)
		{
			if (digits[i] != digits[t - i]) {
				cout << "No" << endl;
				break;
			}
		}
		if (i == t+1) {
			cout << "Yes" << endl;
		}
		
		for (int j = t;j >= 0;j--)
		{
			cout << digits[j];
			if (j > 0) {
				cout << " ";
			}
		}
		cout << endl;
	}
	return 0;
}