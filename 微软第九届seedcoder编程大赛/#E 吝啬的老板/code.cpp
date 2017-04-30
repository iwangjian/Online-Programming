#include<iostream>
using namespace std;
int main()
{
	int n, num, iter, sum;
	while (cin>>n)
	{
		int *que = new int[n];
		int *red = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> num;
			que[i] = num;
			red[i] = 1;
		}
		for (iter = 0; iter < n; iter++)
		{
			for (int j = 0; j < n; j++)
			{
				if (j == 0) {
					if (que[j] > que[j + 1] && red[j] <= red[j+1])
						red[j]++;
				}
				else if (j == n - 1) {
					if (que[j] > que[j - 1] && red[j] <= red[j-1])
						red[j]++;
				}
				else {
					if (que[j] > que[j + 1] && red[j] <= red[j + 1])
					{
						red[j]++;
					}
					if (que[j] > que[j - 1] && red[j] <= red[j - 1])
					{
						red[j]++;
					}
				}
			}
		}
		sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += red[i];
		}
		cout << sum << endl;
		delete[]que;
		que = NULL;
	}
}