#include<iostream>
#include<stack>
using namespace std;
#define MAX 500
#define INT_MAX 1000000
int city[MAX][MAX] = { 0 };
int value[MAX][MAX] = { 0 };
bool visited[MAX];
int dist[MAX];
int path[MAX];
int cost[MAX];
void dijkstra(int n, int src, int dest)
{
	for (int i = 0; i < n; i++)
	{
		if (city[src][i] > 0 && i != src)
		{
			dist[i] = city[src][i];
			cost[i] = value[src][i];
			path[i] = src;
		}
		else {
			dist[i] = INT_MAX;
			cost[i] = INT_MAX;
			path[i] = -1;
		}
		visited[i] = false;
		path[src] = src;
		dist[src] = 0;
		cost[src] = 0;
	}
	visited[src] = true;
	for (int i = 1; i < n; i++)
	{
		int min = INT_MAX;
		int u;
		for (int j = 0; j < n; j++)
		{
			if (!visited[j] && dist[j] < min) {
				min = dist[j];
				u = j;
			}
		}
		visited[u] = true;
		if (u == dest) {
			return;
		}
		for (int k = 0; k < n; k++)
		{
			if (!visited[k] && city[u][k] > 0) {
				if (dist[k] > dist[u] + city[u][k]) {
					dist[k] = dist[u] + city[u][k];
					cost[k] = cost[u] + value[u][k];
					path[k] = u;
				}
				else if (dist[k] == dist[u] + city[u][k]) {
					if (cost[k] > cost[u] + value[u][k]) {
						cost[k] = cost[u] + value[u][k];
						path[k] = u;
					}
				}
			}
		}
	}
}
void show(int src, int dest)
{
	stack<int> s;
	int v = dest;
	while (v != src)
	{
		s.push(v);
		v = path[v];
	}
	s.push(v);
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	cout << dist[dest] << " " << cost[dest] << endl;
}
int main()
{
	int n, m, src, dest;
	cin >> n >> m >> src >> dest;
	int i, j, d, c;
	for (int k = 0; k < m; k++)
	{
		cin >> i >> j >> d >> c;
		city[i][j] = city[j][i] = d;
		value[i][j] = value[j][i] = c;
	}
	dijkstra(n, src, dest);
	show(src, dest);
	
	return 0;
} 