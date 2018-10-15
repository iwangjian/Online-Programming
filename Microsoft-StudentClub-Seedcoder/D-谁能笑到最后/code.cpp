#include<iostream>
using namespace std;
int main()
{
	int n, k;
	while (cin >> n)
	{
		cin >> k;
		if (n >= 2)
		{
			int last = 0;
			for (int i = 2; i <= n; i++)
			{
				last = (last + k) % i;

			}
			cout << last + 1 << endl;
		}
		else
			cout << 1 << endl;
	}
	return 0;
}