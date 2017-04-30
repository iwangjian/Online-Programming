#include<iostream>
using namespace std;
int main()
{
	int n;
	int num[100000];
	int count[10001] = { 0 };
	cin >> n;
	int i;
	for (i = 0; i < n; i++) {
		cin >> num[i];
		count[num[i]]++;
	}
	for (i = 0; i < n; i++) {
		if (count[num[i]] == 1)
		{
			cout << num[i] << endl;
			break;
		}
	}
	if (i == n) {
		cout << "None" << endl;
	}
	return 0;
}