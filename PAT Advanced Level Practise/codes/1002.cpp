#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	double poly[1001] = { 0 };
	int k1, k2, exp=0;
	int count = 0;
	double temp;
	cin >> k1;
	count = k1;
	for (int i = 0;i < k1;i++)
	{
		cin >> exp >> temp;
		poly[exp] = temp;
	}
	cin >> k2;
	for (int j = 0;j < k2;j++)
	{
		cin >> exp >> temp;
		if (poly[exp] == 0) {
			poly[exp] = temp;
			count++;
		}
		else {
			poly[exp] = poly[exp] + temp;
			if (poly[exp] == 0) {
				count--;
			}		
		}
	}
	cout << count;
	for (int i = 1000;i >= 0;i--)
	{
		if (poly[i] != 0) {
			cout << " " << i << " " << fixed << setprecision(1) << poly[i];
		}
	}
	cout << endl;
	return 0;
}