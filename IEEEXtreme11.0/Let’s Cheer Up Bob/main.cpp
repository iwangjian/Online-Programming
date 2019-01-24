#include<iostream>
#include<vector>
using namespace std;
int cc[9];
int per[9][2];
vector<int> temp;
int s[9];
int judge()
{
	int i;
	//判断行
	for (i = 0; i < 9; i += 3)
	{
		if (cc[i] == cc[i + 1] && cc[i] == cc[i + 2])
		{
			return cc[i];
		}
	}
	//判断列
	for (i = 0; i < 3; ++i)
	{
		if (cc[i] == cc[i + 3] && cc[i] == cc[i + 6])
		{
			return cc[i];
		}
	}
	//判断对角线
	if (cc[0] == cc[4] && cc[0] == cc[8])
	{
		return cc[0];
	}
	if (cc[2] == cc[4] && cc[2] == cc[6])
	{
		return cc[2];
	}
	return 0;
}
void dnf(int i, int n)
{
	if (i == 1)
	{
		int j;
		for (j = 0; j < 9; ++j)
		{
			if (cc[per[j][0] * 3 + per[j][1] - 4] == 0)
			{
				s[n] = per[j][0] * 3 + per[j][1] - 4;
				cc[s[n]] = 1;
				break;
			}
		}
		if (j == 9)
		{
			if (judge() == 1)
				temp.insert(temp.end(), s, s + 9);
			cc[s[n]] = 0;
			s[n] = -1;
			return;
		}
		else
		{
			if (judge() == 0)
			{
				dnf(2,n+1);
				cc[s[n]] = 0;
				s[n] = -1;
			}
			else
			{
				if (judge() == 1)
					temp.insert(temp.end(), s, s + 9);
				cc[s[n]] = 0;
				s[n] = -1;
			}		
		}
	}
	if (i == 2)
	{
		for (int j = 0; j < 3; ++j)
		{
			for (int jj = 0; jj < 3; ++jj)
			{
				if (cc[j * 3 + jj] == 0)
				{
					s[n] = j * 3 + jj;
					cc[s[n]] = 2;
					if (judge() == 0)
					{
						dnf(1,n+1);
						cc[s[n]] = 0;
						s[n] = -1;
					}
					else
					{
						if (judge() == 1)
							temp.insert(temp.end(), s, s + 9);
						cc[s[n]] = 0;
						s[n] = -1;
					}
				}
			}
		}
	}
}
int main()
{
	int i, j;
	int n = 10;
	int row = 10;
	int colum1 = 10;
	int colum2 = 10;
	int colum3 = 10;
	int nn;
	for (i = 0; i < 9; ++i)
	{
		cin >> per[i][0] >> per[i][1];
		cc[i] = 0;
		s[i]=-1;
	}
	s[0] = per[0][0] * 3 + per[0][1] - 4;
	cc[s[0]] = 1;
	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 3; ++j)
		{
			if (cc[i * 3 + j] == 0)
			{
				s[1] = i * 3 + j;
				cc[i * 3 + j] = 2;
				dnf(1,2);
				cc[s[1]] = 0;
				s[1] = -1;
			}
		}
	}
	vector<int>::iterator iter;
	vector<int>::iterator iter1;
	for (iter = temp.begin(); iter != temp.end(); iter += 9)
	{
		nn = 0;
		for (i = 0; i < 9; ++i)
		{
			if (*(iter + i) != -1)
				nn++;
		}
		if (n > nn)
		{
			n = nn;
			iter1 = iter;
		}
		if (n == nn)
		{
			if (*(iter1 + 1) > *(iter + 1) )
			{
				iter1 = iter;
				continue;
			}
			else
			{
				if (*(iter1 + 1) == *(iter + 1))
				{
					if (*(iter1 + 3) > *(iter + 3))
					{
						iter1 = iter;
						continue;
					}
					else
					{
						if (*(iter1 + 3) == *(iter + 3))
						{
							if (*(iter1 + 5) > *(iter + 5))
							{
								iter1 = iter;
								continue;
							}
							else
							{
								if (*(iter1 + 5) == *(iter + 5))
								{
									if (*(iter1 + 7) > *(iter + 7))
									{
										iter1 = iter;
										continue;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	
	for (j = 0; j < 9; ++j)
	{
		if (*(iter1 + j) != -1 && j % 2 == 1)
			cout << int(*(iter1 + j) / 3 + 1) << " " << (*(iter1 + j) % 3 + 1) << endl;
	}
	return 0;
}