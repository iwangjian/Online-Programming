#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	double a[1001] = { 0 };
	double b[1001] = { 0 };
	double c[2002] = { 0 };
	int k;
	int exp;
	double coff;
	cin >> k;
	for (int i = 0;i < k;i++)
	{
		cin >> exp >> coff;
		a[exp] = coff;
	}
	cin >> k;
	for (int i = 0;i < k;i++)
	{
		cin >> exp >> coff;
		b[exp] = coff;
	}
	double temp=0;
	int expSum = 0;
	k = 0;
	for (int i = 0;i < 1001;i++)
	{
		if (a[i] != 0) {
			for (int j = 0;j < 1001;j++)
			{
				if (b[j] != 0) {
					temp = a[i] * b[j];
					expSum = i + j;
					if (c[expSum] == 0) {
						k++;
					}
					c[expSum] += temp;
					if (c[expSum == 0]) {
						k--;
					}
				}
			}
		}
	}
	k = 0;
	for (int i = 0;i <= 2000;i++) {
		if (c[i] != 0)
			k++;
	}
	cout << k;
	for (int i = expSum;i >= 0;i--)
	{
		if (c[i]!=0) {
			cout << " " << i << " " << fixed<<setprecision(1)<<c[i];
		}
	}
	cout << endl;
	return 0;
}