#include<iostream>
using namespace std;
const int MAX = 500;
const int INF = 1000000;
int v[MAX][MAX] = { 0 };
int teams[MAX] = { 0 };
int dists[MAX] = { 0 };
bool visited[MAX] = { false };
int amount[MAX] = { 0 };
int samepath[MAX] = { 0 };

void dijkstra(int src, int dest, int n)
{
	dists[src] = 0;
	amount[src] = teams[src];
	visited[src] = true;
	int city = src;
	while (city != dest)
	{
		for (int i = 0;i < n;i++)
		{
			if (!visited[i])
			{
				if (dists[i] > dists[city] + v[city][i])
				{
					dists[i] = dists[city] + v[city][i];
					amount[i] = amount[city] + teams[i];
					samepath[i] = samepath[city];
				}
				else if (dists[i] == dists[city] + v[city][i])
				{
					samepath[i] += samepath[city];
					if (amount[i] < amount[city] + teams[i]){
						amount[i] = amount[city] + teams[i];
					}
				}
			}
		}
		int min = INF;
		for (int i = 0;i < n;i++)
		{
			if (visited[i] == false && dists[i] < min)
			{
				min = dists[i];
				city = i;
			}
		}
		visited[city] = true;
	}
	return;
}
int main()
{
	int n, m ,src, dest;
	cin >> n >> m >> src >> dest;
	for (int i = 0;i < n;i++)
	{
		cin >> teams[i];
	}
	for (int i = 0;i < n;i++)
	{
		dists[i] = INF;
		samepath[i] = 1;
		for (int j = 0;j < n;j++){
			v[i][j] = INF;
		}
	}
	for (int j = 0;j < m;j++)
	{
		int s, d, w;
		cin >> s >> d >> w;
		v[s][d] = v[d][s] = w;
	}
	dijkstra(src, dest, n);
	cout << samepath[dest] << " " << amount[dest] << endl;
	return 0;
}