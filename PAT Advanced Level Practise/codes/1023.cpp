#include<iostream>
#include<string>  
using namespace std;
int shift(int n)
{
	return 1 << n;
}
int main()
{
	string a;
	cin >> a;
	int len = a.length();
	int carry = 0;
	int tmp;
	int sign1 = 0;
	int sign2 = 0;
	while (len)
	{
		sign1 += shift(a[len - 1] - '0');
		tmp = (a[len - 1] - '0') * 2;
		a[len - 1] = '0' + tmp % 10 + carry;
		sign2 += shift(a[len - 1] - '0');
		carry = (tmp + carry) / 10;
		len--;
	}
	if (sign1 == sign2)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}

	if (carry == 0)
		cout << a << endl;
	else
		cout << carry << a << endl;
	return 0;
}