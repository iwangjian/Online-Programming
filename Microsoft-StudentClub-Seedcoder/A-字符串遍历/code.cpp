#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct str
{
	char s;
	int count;
};
int main()
{
	string ss;
	vector<str> vec;
	while (cin>>ss)
	{
		vec.clear();
		for (unsigned int i = 0; i < ss.length(); i++)
		{
			str temp = { ss[i], 1 };
			if (vec.empty()) {
				vec.push_back(temp);
			}
			else {
				bool is_same = false;
				for (unsigned int j = 0; j < vec.size(); j++)
				{
					if (vec[j].s == ss[i]) {
						vec[j].count += 1;
						is_same = true;
						break;
					}
				}
				if (!is_same)
				{
					vec.push_back(temp);
				}
			}	
		}
		for (int i = 0; i < vec.size(); i++)
		{
			cout << vec[i].s << "(" << vec[i].count << ")";
		}
		cout << endl;
	}
}