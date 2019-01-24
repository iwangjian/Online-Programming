#include<iostream>
using namespace std;
int pre[1000];
int find(int n)
{
	if (pre[n] == n)
		return n;
	else
		return pre[n] = find(pre[n]);
}
void unio(int n,int m)
{
	pre[n] = m;
}
int main() {
	int n, m, f1, f2,a,b;
	int t;
	int loop = 0;
	cin >> t;
	while (t--)
	{
		loop = 0;
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
		{
			pre[i] = i;
		}
		for (int i = 0; i < m; ++i)
		{
			cin >> a >> b;
			f1 = find(a);
			f2 = find(b);
			if (f2 == f1)
			{
				loop = 1;
			}
			else
				unio(f1, f2);
		}
		cout << loop << endl;
	}
	return 0;
}