#include<iostream>
#include<iomanip>
using namespace std;
int maxLoc(double a, double b, double c)
{
	if (a > b) {
		if (a > c) {
			return 0;
		}
		else {
			return 2;
		}
	}
	else {
		if (b > c) {
			return 1;
		}
		else {
			return 2;
		}
	}
}
int main()
{
	double g[3][3];
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			cin >> g[i][j];
		}
	}
	double  maxProf = 1;
	for (int i = 0; i < 3;i++)
	{
		int loc = maxLoc(g[i][0], g[i][1], g[i][2]);
		if (loc == 0) {
			cout << "W" << " ";
			maxProf *= g[i][0];
		}
		else if (loc == 1) {
			cout << "T" << " ";
			maxProf *= g[i][1];
		}
		else {
			cout << "L" << " ";
			maxProf *= g[i][2];
		}
	}
	maxProf = (maxProf*0.65 - 1) * 2;
	cout << fixed<<setprecision(2) << maxProf << endl;
	return 0;
}