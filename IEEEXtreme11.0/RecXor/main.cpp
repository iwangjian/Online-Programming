#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define Rep(i, n) for(int i = 1; i <= n; ++i)
typedef long long LL;
typedef unsigned long long ULL;

const LL INF = 0x3f3f3f3f3f3f3f3fll;
const int N = 200;
const double pi = acos(-1.0);

LL f(LL x) {
	int r = x % 4;
	if(r == 0) return x;
	if(r == 1) return 1;
	if(r == 2) return x+1;
	return 0;
}

int main()
{
	int t;
	cin >> t;
	while(t--) {
		int n, m, s;
		LL d1, d2;
		cin >> m >> n >> s >> d1 >> d2;
		if(d1 > d2) swap(d1, d2);
		LL sum = f((LL)n*m+s-1) ^ f(s-1);
		LL r = (d1-s) / m * m + (d2-s) % m + s;
		LL l = d1 - 1;
		if(l >= r) {
			++l; --r;
			swap(l, r);
		}
		int tot = (d2-s) / m - (d1-s) / m + 1;
		rep(i, tot) {
			sum ^= f(l) ^ f(r);
			l += m; r += m;
		}
		cout << sum << '\n';
	}
	return 0;
}