#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0;i < n; ++i)

int cost[101], cover[101], dis[1234567];
bool in[1234567];

char f(string& s) {
	s.clear();
	char c;
	while((c = getchar()) == ' ');
	if(c < ' ') return c;
	s.push_back(c);
	while((c = getchar()) > ' ') s.push_back(c);
	return c;
}

void input(int &n, int &m) {
	char c;
	unordered_map<string, int> mp;
	while((c = getchar()) != EOF) {
		while(c == ' ') c = getchar();
		cost[n] = c - '0';
		while((c = getchar()) != ' ') {
			cost[n] = cost[n] * 10 + c - '0';
		}
		string s;
		while(f(s) == ' ') {
			if(!mp[s]) mp[s] = ++m;
			cover[n] |= 1 << mp[s] - 1;
		}
		if(s.size()) {
			if(!mp[s]) mp[s] = ++m;
			cover[n] |= 1 << mp[s] - 1;
		}
		++n;
	}

	// while((c = getchar()) != EOF) {
	// 	cost[n] = c - '0';
	// 	while((c = getchar()) != ' ') {
	// 		cost[n] = cost[n] * 10 + c - '0';
	// 	}
	// 	while((c = getchar()) > ' ') {
	// 		string s;
	// 		s.push_back(c);
	// 		while((c = getchar()) > ' ') {
	// 			s.push_back(c);
	// 		}
	// 		if(!mp[s]) mp[s] = ++m;
	// 		cover[n] |= 1 << mp[s] - 1;
	// 		if(c == '\n') {
	// 			++n;
	// 			break;
	// 		}
	// 	}
	// }
}

int main()
{
	int n = 0, m = 0;
	input(n, m);
	int dest = (1<<m) - 1;
	memset(dis, 0x3f, sizeof dis);
	queue<int> q;
	q.push(0);
	dis[0] = 0;
	in[0] = true;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		int x = dis[u];
		in[u] = false;
		rep(i, n) {
			int v = u | cover[i];
			int y = x + cost[i];
			if(y < dis[v]) {
				dis[v] = y;
				if(!in[v]) {
					in[v] = true;
					q.push(v);
				}
			}
		}
	}
	cout << dis[dest] << '\n';
	return 0;
}
