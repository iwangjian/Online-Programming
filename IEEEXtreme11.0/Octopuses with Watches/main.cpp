#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define Rep(i, n) for(int i = 1; i <= n; ++i)
typedef long long LL;

const int INF = 0x3f3f3f3f;

int n, m;
char x[10][10], y[10][10];
int val[10], cnt[3], mx;

inline void check() {
	memcpy(y, x, sizeof x);
	rep(i, n) rep(j, m) y[i][j] += val[i];
	int tot = 0;
	rep(j, m) {
		cnt[0] = cnt[1] = cnt[2] = 0;
		rep(i, n) ++cnt[y[i][j]%3];
		if(cnt[0] < cnt[1]) cnt[0] = cnt[1];
		if(cnt[0] < cnt[2]) cnt[0] = cnt[2];
		tot += cnt[0];
	}
	if(mx < tot) mx = tot;
}

inline void dfs(int _) {
	--_;
	rep(i, 3) {
		val[_] = i;
		if(_) dfs(_);
		else check();
	}
}

int main()
{
	int a;
	cin >> n >> m;
	rep(i, n) rep(j, m) {
		cin >> a;
		a %= 3;
		x[i][j] = a;
	}
	dfs(n);
	cout << mx << endl;
	return 0;
}