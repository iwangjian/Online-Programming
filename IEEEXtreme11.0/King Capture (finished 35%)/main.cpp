#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define Rep(i, n) for(int i = 1; i <= n; ++i)
typedef long long LL;

const int INF = 0x3f3f3f3f;

int head[101], nxt[10101], vv[10101], pre[101], u[5001], v[5001], dis[101], n, m, tot;

inline void add(int a, int b) {
	vv[tot] = b; nxt[tot] = head[a]; head[a] = tot++;
}

void bfs(int s) {
	tot = 0;
	memset(head, -1, sizeof head);
	rep(i, m) {
		add(u[i], v[i]);
		add(v[i], u[i]);
	}
	memset(dis, 0x3f, sizeof dis);
	queue<int> q;
	q.push(s);
	dis[s] = 0;
	while(!q.empty()) {
		int u0 = q.front(); q.pop();
		for(int i = head[u0]; ~i; i = nxt[i]) {
			int v0 = vv[i];
			if(dis[v0] == INF) {
				dis[v0] = dis[u0] + 1;
				pre[v0] = u0;
				q.push(v0);
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	rep(i, m) scanf("%d%d", u+i, v+i);
	int w = 0, mi = INF;
	for(int i = n; i; --i) {
		bfs(i);
		int mx = 0;
		Rep(j, n) mx = max(mx, dis[j]);
		if(mx < mi) mi = mx, w = i;
	}
	cout << w << endl;
	int b;
	while(cin >> b) {
		if(b == w) break;
		bfs(b);
		w = pre[w];
		cout << w << endl;
		if(w == b) break;
	}
	return 0;
}
