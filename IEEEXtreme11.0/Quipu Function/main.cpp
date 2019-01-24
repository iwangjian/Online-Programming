#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0;i < n; ++i)

int main()
{
	int t;
	long long a, b, d;
	cin >> t >> a >> b;
	while(t--) {
		cin >> d;
		long long s = sqrt(b) + 1e-6;
		int ans = 0;
		for(long long i = 1; i <= s; ++i) {
			long long j = (max(a, i*i) + i - 1) / i * i;
			while(j <= b) {
				if(i % d) ++ans;
				if(i*i != j && j/i % d) ++ans;
				j += i;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
