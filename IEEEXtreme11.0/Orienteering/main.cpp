#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define Rep(i, n) for(int i = 1; i <= n; ++i)
typedef long long LL;

const int INF = 0x3f3f3f3f;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int px[31], py[31];
double r[602][602], h[602][602], e[602][602][4], dis[602][602];
bool vis[602][602];
int n, m;

double f(pair<int, int> s, pair<int, int> t) {
	Rep(i, n) Rep(j, m) dis[i][j] = 1e16;
	memset(vis, 0, sizeof vis);
	priority_queue<pair<double, pair<int, int>>> q;
	q.push({0, s});
	dis[s.first][s.second] = 0;
	while(!q.empty()) {
		auto node = q.top(); q.pop();
		if(node.second == t) return node.first;
		int i = node.second.first, j = node.second.second;
		if(vis[i][j]) continue;
		vis[i][j] = true;
		rep(d, 4) {
			int x = i + dx[d], y = j + dy[d];
			double cur = node.first + e[i][j][d];
			if(cur < dis[x][y]) {
				dis[x][y] = cur;
				q.push({cur, {x, y}});
			}
		}
	}
	return dis[t.first][t.second];
}

int main()
{
	int p;
	cin >> n >> m >> p;
	rep(i, p+1) cin >> px[i] >> py[i], ++px[i], ++py[i];
	Rep(i, n) Rep(j, m) scanf("%lf", r[i]+j);
	Rep(i, n) Rep(j, m) scanf("%lf", h[i]+j);
	Rep(i, n) r[i][0] = r[i][m+1] = h[i][0] = h[i][m+1] = 1e16;
	Rep(i, m) r[0][i] = r[n+1][i] = h[0][i] = h[n+1][i] = 1e16;
	Rep(i, n) Rep(j, m) {
		rep(d, 4) {
			int x = i + dx[d], y = j + dy[d];
			e[i][j][d] = (r[i][j] + r[x][y]) / 2 * exp(3.5 * fabs((h[x][y]-h[i][j])/10 + 0.05));
		}
	}
	double ans = 0;
	Rep(i, p) ans += f({px[i-1], py[i-1]}, {px[i], py[i]});
	printf("%.0lf\n", ceil(ans));
	return 0;
}
