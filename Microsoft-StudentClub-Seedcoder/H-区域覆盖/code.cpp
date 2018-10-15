#include<iostream>  
#include<algorithm>  
using namespace std;
#define N 10005  
int f[N];
int find(int x)
{
	return x == f[x] ? x : f[x] = find(f[x]);
}
int main()
{
	int n, m;
	while (cin>>n)
	{
		cin>>m;
		int i;
		int x, y;
		for (i = 0; i <= n; i++)
			f[i] = i;
		for (i = 0; i < m; i++)
		{
			cin >> x >> y;
			x = find(x);
			y = find(y);
			if (x != y) f[x] = y;
		}
		int ans = 0;
		for (i = 1; i <= n; i++)
			if (f[i] == i)
				ans++; 
		cout << ans - 1 << endl;
	}                                
	return 0;
}