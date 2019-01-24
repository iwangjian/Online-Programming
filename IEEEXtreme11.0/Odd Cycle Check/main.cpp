#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define Rep(i, n) for(int i = 1; i <= n; ++i)
typedef long long LL;
typedef unsigned long long ULL;

const LL INF = 0x3f3f3f3f3f3f3f3fll;
const int mod = 1000000007;
const int N = 200;
const double pi = acos(-1.0);

int x[20023];
vector<int> g[12345];

int main()
{
	int n;
	cin >> n;
	int id = 2, u, v;
	while(true) {
		scanf("%d%d", &u, &v);
		if(!x[u]) swap(u, v);
		if(!x[u]) {
			g[id/2].push_back(u);
			g[id/2].push_back(v);
			x[u] = id++;
			x[v] = id++;
		}
		else if(x[v]) {
			if(x[u] != x[v] && (x[u]^x[v]) != 1) {
				if(g[x[u]/2].size() < g[x[v]/2].size()) swap(u, v);
				int temp = x[v] ^ x[u] ^ 1, b = x[u] / 2, c = x[v] / 2;
				for(int a : g[c]) {
					x[a] ^= temp; g[b].push_back(a);
				}
			}
			else if(x[u] == x[v]) {
				cout << 0 << endl;
				break;
			}
		}
		else {
			x[v] = x[u] ^ 1;
			g[x[u]/2].push_back(v);
		}
		cout << 1 << endl;
	}
	return 0;
}