#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define Rep(i, n) for(int i = 1; i <= n; ++i)
typedef long long LL;

const int INF = 0x3f3f3f3f;

int head[100100], vv[600600], nxt[600600], pre[100100], low[100100];
bool loop[100100];
int flag = -1, cur = 0;

inline void add(int u, int v) {
	static int i = 0;
	vv[i] = v; nxt[i] = head[u]; head[u] = i++;
}

int dfs(int u, int p) {
	int lowu = pre[u] = ++cur;
	for(int i = head[u]; ~i; i = nxt[i]) {
		int v = vv[i];
		if(p == v) continue;
		if(!pre[v]) {
			int lowv = dfs(v, u);
			lowu = min(lowu, lowv);
			if(lowv <= pre[u]) loop[u] = true;
		}
		else if(pre[v] < pre[u]) lowu = min(lowu, pre[v]), loop[u] = true;
	}
	low[u] = lowu;
	return lowu;
}

int main()
{
	int n, m;
	cin >> n >> m;
	int u, v;
	memset(head, -1, sizeof head);
	rep(i, m) {
		scanf("%d%d", &u, &v);
		add(u, v); add(v, u);
	}
	Rep(i, n) if(!pre[i]) {
		dfs(i, i);
	}
	Rep(i, n) if(!loop[i]) printf("%d\n", i);
	return 0;
}
