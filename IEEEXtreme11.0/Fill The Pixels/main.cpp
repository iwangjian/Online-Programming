#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define Rep(i, n) for(int i = 1; i <= n; ++i)
typedef long long LL;
typedef unsigned long long ULL;

const LL INF = 0x3f3f3f3f3f3f3f3fll;
const int N = 200;
const double pi = acos(-1.0);

char g[1002][1002], h[1002][1002];

void dfs(int x, int y) {
	if(g[x][y] != '1') return;
	g[x][y] = '0';
	dfs(x-1, y-1); dfs(x-1, y+1); dfs(x+1, y-1); dfs(x+1, y+1);
}

void dfs3(int x, int y) {
	if(h[x][y] != '1') return;
	h[x][y] = '0';
	dfs3(x-1, y); dfs3(x, y+1); dfs3(x, y-1); dfs3(x+1, y);
	dfs3(x-1, y-1); dfs3(x-1, y+1); dfs3(x+1, y-1); dfs3(x+1, y+1);
}

void dfs2(int x, int y) {
	if(g[x][y] != '1') return;
	g[x][y] = '0';
	dfs2(x-1, y); dfs2(x, y+1); dfs2(x, y-1); dfs2(x+1, y);
}

int main()
{
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> m >> n;
		gets(g[1]+1);
		Rep(i, n) gets(g[i]+1);
		Rep(i, m+1) g[n+1][i] = 0;
		memcpy(h, g, sizeof g);
		int a = 0;
		Rep(i, n) Rep(j, m) {
			if(g[i][j] == '1') {
				dfs(i, j);
				++a;
			}
		}
		int b = 0;
		memcpy(g, h, sizeof g);
		Rep(i, n) Rep(j, m) {
			if(g[i][j] == '1') {
				dfs2(i, j);
				++b;
			}
		}
		int c = 0;
		Rep(i, n) Rep(j, m) {
			if(h[i][j] == '1') {
				dfs3(i, j);
				++c;
			}
		}
		cout << b << ' ' << a << ' ' << c << '\n';
	}
}