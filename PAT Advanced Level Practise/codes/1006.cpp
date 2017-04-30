#include<iostream>
#include<string>
using namespace std;
int main()
{
	int m;
	cin >> m;
	string *ids = new string[m];
	int *sins = new int[m];
	int *souts = new int[m];
	for (int i = 0;i < m;i++)
	{
		cin >> ids[i];
		char time[9] = { 0 };
		for (int j = 0;j < 8;j++) {
			cin >> time[j];
		}
		sins[i] = (time[0] - '0') * 100000 + (time[1] - '0') * 10000 + (time[3] - '0') * 1000 + (time[4] - '0') * 100 + (time[6] - '0') * 10 + (time[7] - '0');
		for (int j = 0;j < 8;j++) {
			cin >> time[j];
		}
		souts[i]= (time[0] - '0') * 100000 + (time[1] - '0') * 10000 + (time[3] - '0') * 1000 + (time[4] - '0') * 100 + (time[6] - '0') * 10 + (time[7] - '0');

	}
	int earliest = 0, latest = 0;
	for (int i = 1;i < m;i++)
	{
		if (sins[i] < sins[earliest]) {
			earliest = i;
		}
		if (souts[i]  > souts[latest]) {
			latest = i;
		}
	}
	cout << ids[earliest] << " " << ids[latest] << endl;
	
	delete[]ids;
	ids = NULL;
	delete[]sins;
	sins = NULL;
	delete[]souts;
	souts = NULL;
	return 0;
}