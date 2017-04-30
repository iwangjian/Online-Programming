#include<iostream>
#include<cmath>
using namespace std;
bool isPrime(int m)
{
	if (m == 0 || m == 1) {
		return false;
	}
	if (m == 2) {
		return true;
	}
	else {
		for (int k = 2; k*k <= m; k++)
		{
			if (m%k == 0) {
				return false;
			}
		}
	}
	return true;
}
int reverse(int n, int d)
{
	int digits[20];
	int t = 0, rn=0;
	while (n > 0)
	{
		digits[t] = n%d;
		t++;
		n = n / d;
	}
	t = t - 1;
	for (int i = 0; i <= t; i++)
	{
		rn = rn + digits[i] * int(pow(d, t - i));
	}
	return rn;
}
int main()
{
	int n, d;
	while (cin >> n)
	{
		if (n < 0)
			break;
		cin >> d;
		int rn = reverse(n, d);
		if (isPrime(n) && isPrime(rn)) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	return 0;
}