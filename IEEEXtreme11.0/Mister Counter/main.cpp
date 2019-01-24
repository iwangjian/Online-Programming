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

int a[N], pos[N*4];

void build(int l, int r, int i) {
	if(l == r) {
		pos[i] = l;
		return;
	}
	int m = l + r >> 1, ls = i << 1, rs = ls | 1;
	build(l, m, ls); build(m+1, r, rs);
	if(pos[rs] == m+1 && a[m+1] < a[m]) pos[i] = pos[ls];
	else pos[i] = pos[rs];
}

int query(int l, int r, int L, int R, int i) {
	if(l == L && r == R) return pos[i];
	int m = L + R >> 1, ls = i << 1, rs = ls | 1;
	if(l > m) return query(l, r, m+1, R, rs);
	if(r <= m) return query(l, r, L, m, ls);
	int p = query(m+1, r, m+1, R, rs);
	if(p == m+1 && a[m+1] < a[m]) return query(l, m, L, m, ls);
	return p;
}

int main()
{
	int n;
	cin >> n;
	Rep(i, n) scanf("%d", a+i);
	build(1, n, 1);
	int q, l, r;
	cin >> q;
	while(q--) {
		scanf("%d%d", &l, &r);
		int p = query(l, r, 1, n, 1);
		if(p == l) printf("0\n");
		else {
			if((r-p&1) == 0) {
				int mid = r + p >> 1;
				if(r == p || a[mid] > a[p-1] && a[mid+1] < a[p-1]) printf("%d\n", r-p+2);
				else printf("%d\n", r-p+1);
			}
			else printf("%d\n", r-p+2);
		}
	}
	return 0;
}