#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define Rep(i, n) for(int i = 1; i <= n; ++i)

long long sum[2067890];
int x[2067890];
int dim[6] = {1}, base[6], cnt[6], temp[6];
int qa[6], diff[6];

int main()
{
	int d;
	cin >> d;
	Rep(i, d) cin >> dim[i];
	base[d] = 1;
	for(int i = d-1; i >= 0; --i) base[i] = base[i+1] * (dim[i+1] + 1);
	int n = 1;
	Rep(i, d) n *= dim[i];
	Rep(i, d) cnt[i] = 1;
	const int r = (1 << d) - 1;
	Rep(i, n) {
		int index = cnt[d];
		for(int i = 1; i < d; ++i) index += cnt[i] * base[i];
		scanf("%d", x+index);
		sum[index] = x[index];
		int pos = 0;
		while(pos < r) {
			int _ = 0;
			Rep(j, d) {
				if(pos & (1<<j-1)) ++_, temp[j] = cnt[j];
				else temp[j] = cnt[j] - 1;
			}
			int k = temp[d];
			for(int i = 1; i < d; ++i) k += temp[i] * base[i];
			_ = d - _;
			if(_ & 1) sum[index] += sum[k];
			else sum[index] -= sum[k];
			++pos;
		}
		++cnt[d];
		int cur = d;
		while(cnt[cur] > dim[cur]) {
			cnt[cur] = 1; ++cnt[--cur];
		}
	}
	int q;
	cin >> q;
	while(q--) {
		Rep(i, d) scanf("%d", qa+i);
		Rep(i, d) scanf("%d", cnt+i), diff[i] = cnt[i] - qa[i] + 1;
		int index = cnt[d];
		for(int i = 1; i < d; ++i) index += cnt[i] * base[i];
		long long ans = sum[index];
		int pos = 0;
		while(pos < r) {
			int _ = 0;
			Rep(j, d) {
				if(pos & (1<<j-1)) ++_, temp[j] = cnt[j];
				else temp[j] = cnt[j] - diff[j];
			}
			int k = temp[d];
			for(int i = 1; i < d; ++i) k += temp[i] * base[i];
			_ = d - _;
			if(_ & 1) ans -= sum[k];
			else ans += sum[k];
			++pos;
		}
		printf("%d\n", (int)ans);
	}
	return 0;
}
