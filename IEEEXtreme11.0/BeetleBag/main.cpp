#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define Rep(i, n) for(int i = 1; i <= n; ++i)
typedef long long LL;
typedef unsigned long long ULL;

const LL INF = 0x3f3f3f3f3f3f3f3fll;
const int mod = 1000000007;
const int N = 250251;
const double pi = acos(-1.0);

int dp[505];

int main()
{
	int t;
	cin >> t;
	while(t--) {
		int c, n;
		cin >> c >> n;
		memset(dp, 0, sizeof dp);
		int w, f;
		rep(i, n) {
			cin >> w >> f;
			for(int i = c; i >= w; --i) {
				dp[i] = max(dp[i], dp[i-w]+f);
			}
		}
		cout << dp[c] << '\n';
	}
	return 0;
}