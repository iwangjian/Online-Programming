#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int *a = new int[n];
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	
	int sum = 0;
	int max = a[0];
	int first = 0, last = 0;
	for (int i = 0;i < n;i++)
	{
		sum = 0;
		for (int j = i;j < n;j++)
		{
			sum += a[j];
			if (sum > max) {
				max = sum;
				first = i;
				last = j;
			}
		}
	}
	if (max<0) {
		cout << 0 << " "<<a[0] <<" "<< a[n - 1] << endl;
	}
	else {
		cout << max << " " << a[first] << " " << a[last] << endl;
	}
	delete[]a;
	a = NULL;
	return 0;
}