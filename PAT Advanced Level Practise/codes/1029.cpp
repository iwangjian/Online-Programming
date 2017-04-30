#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n1, n2, pm;
	vector<long int> vec1;
	vector<long int> vec2;
	long int num;
	cin >> n1;
	for (int i = 0; i < n1; i++)
	{
		cin >> num;
		vec1.push_back(num);
	}
	cin >> n2;
	for (int i = 0; i < n2; i++)
	{
		cin >> num;
		vec2.push_back(num);
	}
	if ((n1 + n2) % 2 == 0) {
		pm = (n1 + n2) / 2 - 1;
	}
	else {
		pm = (n1 + n2) / 2;
	}

	int p1 = 0, p2 = 0;
	int tmp = -1;
	while (tmp <= pm)
	{
		if (p1 < n1 && vec1[p1] <= vec2[p2]) {
			tmp++;
			if (tmp == pm)
			{
				cout << vec1[p1] << endl;
				break;
			}
			p1++;
		}
		else if(p2 < n2){
			tmp++;
			if (tmp == pm)
			{
				cout << vec2[p2] << endl;
				break;
			}
			p2++;
		}
	}
	return 0;
}