#include <iostream>  
#include <string>  
#include <algorithm>  
using namespace std;
bool isPalindrome(const string &str)
{
	string s = str;
	reverse(s.begin(), s.end());
	return s == str;
}
int main()
{
	string s;
	while (cin>>s)
	{
		string add_str;
		string temp;
		if(isPalindrome(s)) {
			cout << s << endl;
		}
		else {
			for (int i = s.length() - 1; i > 0; i--)
			{
				temp = s.substr(0, i);
				add_str += s[i];
				if (isPalindrome(temp))
				{
					break;
				}
			}
			s = add_str + s;
			cout << s << endl;
		}
	}
}