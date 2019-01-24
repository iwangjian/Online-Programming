#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define Rep(i, n) for(int i = 1; i <= n; ++i)
typedef long long LL;

const int mm = 1000000006;
const int xxx = 500000003; 
const int N = 1000000;

int x[1000123] = {1}, inv[1000123];

LL qpow(LL y, int n, int mod) {
	LL res = 1;
	while(n) {
		if(n&1) res = res * y % mod;
		n >>= 1;
		y = y * y % mod;
	}
	return res;
}

int a[2], m[2];

void exgcd(LL a, LL b, LL &x, LL &y) {
    if(b) {
        exgcd(b, a % b, y, x);
        y -= a / b * x;
    }
    else x = 1, y = 0;
}

LL in(LL a, LL m) {
    LL x, y;
    exgcd(a, m, x, y);
    return (x % m + m) % m;
}

int crt() {
	LL M = mm, ret = 0;
	rep(i, 2) {
		LL w = m[i^1];
		ret = (ret + w * in(w, m[i]) % M * a[i]) % M;
	}
	return (ret + M) % M;
}

int main()
{
	Rep(i, N) x[i] = x[i-1] * (LL)i % xxx;
	inv[N] = qpow(x[N], xxx-2, xxx);
	for(int i = N; i; --i) inv[i-1] = inv[i] * (LL)i % xxx;
	int t;
	cin >> t;
	while(t--) {
		int _a, b, c;
		cin >> _a >> b >> c;
		if((b&c) == c) a[0] = 1;
		else a[0] = 0;
		m[0] = 2;
		m[1] = xxx;
		a[1] = (LL)inv[c] * x[b] % xxx * inv[b-c] % xxx;
		cout << qpow(_a, crt(), mm+1) << '\n';
	}
	return 0;
}
