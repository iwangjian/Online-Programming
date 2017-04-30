#include<iostream>
using namespace std;
int main()
{
	int n, sum = 0;
	int floor[100];
	cin >> n;
	for (int i = 0; i < n;i++)
	{
		cin >> floor[i];
	}
	sum = sum + n * 5;
	sum = sum + floor[0] * 6;
	for (int j = 1;j < n;j++)
	{
		if (floor[j] > floor[j - 1]) {
			sum += (floor[j] - floor[j - 1]) * 6;
		}
		else {
			sum += (floor[j - 1] - floor[j]) * 4;
		}
	}
	cout << sum << endl;
	return 0;
}