#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define Rep(i, n) for(int i = 1; i <= n; ++i)
typedef long long LL;
typedef unsigned long long ULL;

const LL INF = 0x3f3f3f3f3f3f3f3fll;
const int N = 200;
const double pi = acos(-1.0);

LL val[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
LL x[20020], dis[20020];

int head[20020], nxt[40040], vv[40040], c[20020], y[20020];
bool in[20020];

inline void add(int u, int v) {
	static int i = 0;
	vv[i] = v; nxt[i] = head[u]; head[u] = i++;
}

void spfa(int n) {
	memset(dis, 0x3f, sizeof dis);
	dis[1] = 0;
	queue<int> q;
	q.push(1);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		in[u] = false;
		for(int i = head[u]; ~i; i = nxt[i]) {
			int v = vv[i];
			LL d = dis[u] + c[i/2] * 1000000000ll - y[v];
			if(d < dis[v]) {
				dis[v] = d;
				if(!in[v]) {
					q.push(v);
					in[v] = true;
				}
			}
		}
	}
}

int main()
{
	memset(head, -1, sizeof head);
	Rep(i, 14) val[i] = val[i-1] * val[i];
	int n, m;
	cin >> n >> m;
	Rep(i, n) scanf("%lld", x+i);
	sort(x+1, x+n+1);
	Rep(i, n) y[i] = upper_bound(val, val+15, x[i]) - val;
	LL u, v;
	rep(i, m) {
		scanf("%lld%lld%d", &u, &v, c+i);
		u = lower_bound(x+1, x+1+n, u) - x;
		v = lower_bound(x+1, x+1+n, v) - x;
		add(u, v); add(v, u);
	}
	spfa(n);
	int ans = dis[n] % 1000000000;
	if(ans) ans = 1000000000 - ans;
	cout << ans+y[1] << '\n';
}