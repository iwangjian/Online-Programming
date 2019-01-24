#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define Rep(i, n) for(int i = 1; i <= n; ++i)
typedef long long LL;
typedef unsigned long long ULL;

const int INF = 0x3f3f3f3f;
const int N = 200;
const double pi = acos(-1.0);

double x[130];

int main()
{
	double r;
	cin >> r;
	char c;
	rep(i, 26) {
		cin >> c;
		cin >> x[c];
		x[c+32] = x[c];
	}
	bool _ = false;
	double ans = 0, pre = 0;
	while((c = getchar()) != EOF) {
		if(c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') {
			if(_) {
				double temp = x[c] - pre;
				if(temp < 0) temp = -temp;
				if(temp > 180) temp = 360 - temp;
				ans += sin(temp*pi/360);
			}
			else _ = true;
			pre = x[c];
		}
	}
	printf("%.0lf\n", (ans*2+1)*r);
}