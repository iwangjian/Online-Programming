#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define Rep(i, n) for(int i = 1; i <= n; ++i)
typedef long long LL;
typedef unsigned long long ULL;

const LL INF = 0x3f3f3f3f3f3f3f3fll;
const int mod = 1000000007;
const int N = 200;
const double pi = acos(-1.0);
 
int x[123456];

int main()
{
	x[1] = 1;
	int n;
	cin >> n;
	for(int i = 2; i <= n; ++i) {
		x[i] = x[i-1] + x[i/2];
		if(x[i] >= mod) x[i] -= mod;
	}
	cout << x[n] << endl;
	return 0;
}