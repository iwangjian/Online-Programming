#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool isPalindromic(vector<int> num)
{
	bool flag = true;
	unsigned int len = num.size();
	for (unsigned int i = 0; i <= len / 2; i++)
	{
		if (num[i] != num[len - 1 - i]) {
			flag = false;
			break;
		}
	}
	return flag;
}
int main()
{
	string str;
	int k;
	cin >> str >> k;
	vector<int> number;
	vector<int> reverse_num;
	vector<int> sum_num;
	for (unsigned int i = 0; i < str.length(); i++)
	{
		number.push_back(str[i] - '0');
	}
	if (isPalindromic(number))
	{
		for (unsigned int j = 0; j < number.size(); j++)
		{
			cout << number[j];
		}
		cout << endl << 0 << endl;
		return 0;
	}
	int count = 1;
	for (; count <= k; count++)
	{
		
		reverse_num.clear();
		sum_num.clear();
		int carry = 0;
		int sum = 0;
		for (int j = number.size()-1; j >= 0; j--)
		{
			reverse_num.push_back(number[j]);
		}
		for (int j = number.size() - 1; j >= 0; j--)
		{
			sum = number[j] + reverse_num[j] + carry;
			sum_num.push_back(sum % 10);
			carry = sum / 10;
		}
		if (carry > 0) {
			sum_num.push_back(carry);
		}
		if (isPalindromic(sum_num))
		{
			for (unsigned int j = 0; j < sum_num.size(); j++)
			{
				cout << sum_num[j];
			}
			cout << endl << count << endl;
			return 0;
		}
		else {
			number = sum_num;
		}
	}
	for (int i = number.size() - 1; i >= 0; i--)
	{
		cout << number[i];
	}
	cout << endl << k << endl;
	return 0;
}