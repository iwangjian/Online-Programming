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

int main()
{
	int t;
	cin >> t;
	while(t--) {
		LL a, b;
		int ans = 0;
		scanf("%lld%lld", &a, &b);
		while(a != b) {
			if(a < b) swap(a, b);
			a /= 2;
			++ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}