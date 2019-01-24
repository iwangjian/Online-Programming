#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define Rep(i, n) for(int i = 1; i <= n; ++i)
typedef long long LL;
typedef unsigned long long ULL;

const LL INF = 0x3f3f3f3f3f3f3f3fll;
const int mod = 1000000007;
const int N = 1000;
const double pi = acos(-1.0);

int x[1000123], y[1000123], val[4123][4123];

int main()
{
	int n, m, k, d;
	cin >> n >> m >> k;
	Rep(i, k) {
		scanf("%d%d%d", x+i, y+i, &d);
		int a = x[i] - y[i] + 2*N;
		int b = x[i] + y[i] + N;
		x[i] = a; y[i] = b;
		++val[a-d][b-d];
		--val[a+d+1][b-d];
		--val[a-d][b+d+1];
		++val[a+d+1][b+d+1];
	}
	Rep(j, 3000) Rep(i, 3000) {
		val[i][j] += val[i-1][j];
	}
	Rep(i, 3000) Rep(j, 3000) {
		val[i][j] += val[i][j-1];
	}
	int mx = -1, ans;
	Rep(i, k) {
		if(val[x[i]][y[i]] > mx) {
			mx = val[x[i]][y[i]]; ans = i;
		}
	}
	cout << ans << ' ' << mx-1 << '\n';
	return 0;
}