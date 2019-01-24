#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define Rep(i, n) for(int i = 1; i <= n; ++i)
typedef long long LL;

const int INF = 0x3f3f3f3f;
const int N = 200;

struct dinic{
	int first[6620], dis[6620], cur[6620], nxt[240400], vv[240400], cap[240400], tot, s, t;
	void init(int _s) {
		memset(first, -1, sizeof(first));
		tot = 0; s = _s; t = s+1;
	}
	
	void add(int u, int v, int c) {
		vv[tot] = v; cap[tot] = c; nxt[tot] = first[u]; first[u] = tot++;
		vv[tot] = u; cap[tot] = 0; nxt[tot] = first[v]; first[v] = tot++;
	}
	
	bool bfs() {
		memset(dis, 0x3f, sizeof(dis));
		dis[s] = 0;
		queue<int>q;
		q.push(s);
		while(!q.empty()) {
			int u = q.front(); q.pop();
			for(int i = first[u]; ~i; i = nxt[i]) {
				int v = vv[i];
				if(dis[v] == INF && cap[i]) {
					dis[v] = dis[u] + 1;
					q.push(v);
				}
			}
		}
		return dis[t] < INF;
	}
	
	int dfs(int u, int a) {
		if(u == t || !a) return a;
		int flow = 0, f;
		for(int& i = cur[u]; ~i; i = nxt[i]) {
			int v = vv[i];
			if(dis[v] == dis[u] + 1 && (f = dfs(v, min(a, cap[i])))) {
				cap[i] -= f;
				cap[i^1] += f;
				flow += f;
				a -= f;
				if(!a) break;
			}
		}
		return flow;
	}
	
	int maxflow() {
		int flow = 0;
		while(bfs()) {
			memcpy(cur, first, sizeof(first));
			flow += dfs(s, INF);
		}
		return flow;
	}
} solve;

bool use[233];

void input(int n) {
	char c;
	int cnt = 0;
	while((c = getchar()) != '\n');
	while((c = getchar()) != EOF) {
		while(true) {
			rep(i, n) use[i] = false;
			while(c == ' ') c = getchar();
			if(c < ' ') break;
			int val = c - '0';
			while((c = getchar()) > ' ') val = val * 10 + c - '0';
			cout << val << ' ';
			use[val] = true;
		}
		rep(i, n) if(!use[i] && cnt != i) {
			solve.add(cnt, N+i, 1);
		}
		++cnt;
	}
}

int main()
{
	int n;
	cin >> n;
	solve.init(2*N);
	rep(i, n) solve.add(2*N, i, 1), solve.add(i+N, 2*N+1, 1);
	rep(i, n) input(n);
	return 0;
}