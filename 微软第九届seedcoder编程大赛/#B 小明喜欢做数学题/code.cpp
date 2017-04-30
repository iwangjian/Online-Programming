#include<iostream>
using namespace std;
const int N = 2;
const int mod = 100007;
struct Matrix {
	long long int m[N][N];
};
Matrix A = {
	1,1,
	1,0
};
Matrix B = {
	1,0,
	0,1
};
Matrix fun(Matrix a, Matrix b) 
{
	Matrix c;
	for (int i = 0; i<N; i++)
	{
		for (int j = 0; j<N; j++)
		{
			c.m[i][j] = 0;
			for (int k = 0; k<N; k++)
				c.m[i][j] += a.m[i][k] * b.m[k][j] % mod;

			c.m[i][j] = c.m[i][j] % mod;
		}
	}
	return c;
}
Matrix power(int k)
{
	Matrix ans = B, p = A;
	while (k)
	{
		if (k & 1)
		{
			ans = fun(ans, p);
			k--;
		}
		k >>= 1;
		p = fun(p, p);
	}
	return ans;
}
int main()
{
	int a;
	while (cin >> a)
	{
		Matrix ans = power(a);
		cout << ans.m[0][0] << endl;
	}
}
