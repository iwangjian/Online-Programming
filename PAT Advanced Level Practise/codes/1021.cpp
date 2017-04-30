#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int MAX = 10001;
bool visited[MAX];
int dist[MAX];
vector<int> adj[MAX];

int dfs(int src)
{
	int maxDist = -1;
	bool flag = false;
	visited[src] = true;
	vector<int>::iterator iter = adj[src].begin();
	while (iter != adj[src].end())
	{
		int i = *iter;
		if (!visited[i]) {
			flag = true;
			int tmp = dfs(i);
			if (maxDist < tmp) {
				maxDist = tmp;
			}
		}
		iter++;
	}
	if (!flag) {
		return 1;
	}
	return maxDist + 1;
}
void init(int n)
{
	for (int i = 1; i <= n; i++)
	{
		visited[i] = false;
	}
}
int main()
{
	int n;
	int a, b;
	cin >> n;
	init(n);
	for (int i = 1; i <= n - 1; i++)
	{
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int count = 1;
	int max_dist = -1;
	for (int i = 1; i <= n; i++)
	{
		init(n);
		dist[i] = dfs(i);
		if (dist[i] > max_dist) {
			max_dist = dist[i];
		}
		for (int j = 1; j <= n; j++)
		{
			if (!visited[j]) {
				count++;
				dfs(j);
			}
		}
		if (count > 1)
		{
			break;
		}
	}
	if (count > 1)
	{
		cout << "Error: " << count << " components" << endl;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (dist[i] == max_dist) {
				cout << i << endl;
			}
		}
	}
	return 0;
}