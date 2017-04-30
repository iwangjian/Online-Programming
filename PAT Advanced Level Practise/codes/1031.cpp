#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int n = s.length();
	int n1, n2;
	for (n2 = 3;n2 < n + 2;n2++)
	{
		if ((n + 2 - n2) % 2 == 0) {
			n1 = (n + 2 - n2) / 2;
			if (n1 <= n2) {
				break;
			}
		}
	}

	for (int i = 0; i < n1-1; i++)
	{
		cout << s[i];
		for (int j = 0;j < n2 - 2;j++)
		{
			cout << " ";
		}
		cout << s[n - 1 - i] << endl;
	}
	for (int k = n1 - 1;k <= n1 + n2 - 2;k++)
	{
		cout << s[k];
	}
	cout << endl;
	return 0;
}