#include<iostream>
#include<string>  
using namespace std;
char getRGB(int n)
{
	char c;
	if (n == 10) {
		c = 'A';
	}
	else if (n == 11) {
		c = 'B';
	}
	else if (n == 12) {
		c = 'C';
	}
	else {
		c = n + '0';
	}
	return c;
}
int main()
{
	int r, g, b;
	char color[6];
	cin >> r >> g >> b;
	if (r == 0) {
		color[0] = '0';
		color[1] = '0';
	}
	else	{
		int low = r % 13;
		int high = r / 13;
		color[0] = getRGB(high);
		color[1] = getRGB(low);
	}
	if (g == 0) {
		color[2] = '0';
		color[3] = '0';
	}
	else {
		int low = g % 13;
		int high = g / 13;
		color[2] = getRGB(high);
		color[3] = getRGB(low);
	}
	if (b == 0) {
		color[4] = '0';
		color[5] = '0';
	}
	else {
		int low = b % 13;
		int high = b / 13;
		color[4] = getRGB(high);
		color[5] = getRGB(low);
	}
	cout << "#";
	for (int i = 0;i < 6;i++)
	{
		cout << color[i];
	}
	cout << endl;
	return 0;
}