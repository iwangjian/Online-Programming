#include<iostream>
#include<string>
#include<cmath>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int get_rank(vector<double> course_vec, double score)
{
	sort(course_vec.begin(), course_vec.end());
	int rank;
	int size = course_vec.size();
	for (rank = 1;rank <= size;rank++)
	{
		if (course_vec[size - rank] == score) {
			return rank;
		}
	}
	return 0;
}
string int_to_string(int rank)
{
	string val;
	if (rank < 10) {
		val = rank + '0';
	}
	else if (rank < 100) {
		val = rank / 10 + '0';
		val += rank % 10 + '0';
	}
	else if (rank < 1000) {
		val = rank / 100 + '0';
		val += (rank % 100) / 10 + '0';
		val += rank % 10 + '0';
	}
	else if (rank <= 2000) {
		val = rank / 1000 + '0';
		val += (rank % 1000) / 100 + '0';
		val += (rank / 100) / 10 + '0';
		val += rank % 10 + '0';
	}
	return val;
}
int main()
{
	int n, m;
	map<string, vector<double>> mp;
	map<string, vector<double>>::iterator iter;
	vector<string> students;
	vector<string> ranks;
	vector<double> avg_vec;
	vector<double> c_vec;
	vector<double> m_vec;
	vector<double> e_vec;
	cin >> n >> m;
	for (int i = 0;i < n;i++)
	{
		string id;
		double a, c, m, e;
		vector<double> vec;
		cin >> id >> c >> m >> e;
		a = (c + m + e) / 3;
		vec.push_back(a); avg_vec.push_back(a);
		vec.push_back(c); c_vec.push_back(c);
		vec.push_back(m); m_vec.push_back(m);
		vec.push_back(e); e_vec.push_back(e);
		mp.insert(pair<string, vector<double>>(id, vec));
	}
	for (int i = 0;i < m;i++)
	{
		string sid;
		cin >> sid;
		students.push_back(sid);
	}

	for (unsigned int i = 0;i < students.size();i++)
	{
		iter = mp.find(students[i]);
		if (iter == mp.end()) {
			ranks.push_back("N/A");
		}
		else {
			vector<double> vec = iter->second;
			string val;
			int avg_rank = get_rank(avg_vec, vec[0]);
			int c_rank = get_rank(c_vec, vec[1]);
			int m_rank = get_rank(m_vec, vec[2]);
			int e_rank = get_rank(e_vec, vec[3]);
			if (avg_rank <= c_rank && avg_rank <= c_rank&&avg_rank <= m_rank&&avg_rank <= e_rank) {
				val = int_to_string(avg_rank);
				val += " A";
				ranks.push_back(val);
			}
			else if (c_rank <= m_rank&&c_rank <= e_rank) {
				val = int_to_string(c_rank);
				val += " C";
				ranks.push_back(val);
			}
			else if (m_rank <= e_rank) {
				val = int_to_string(m_rank);
				val += " M";
				ranks.push_back(val);
			}
			else {
				val = int_to_string(e_rank);
				val += " E";
				ranks.push_back(val);
			}
		}
	}
	for (unsigned int i = 0;i < ranks.size();i++)
	{
		cout << ranks[i] << endl;
	}
	return 0;
}