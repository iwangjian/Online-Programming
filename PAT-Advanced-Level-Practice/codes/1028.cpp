#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
struct stuInfo
{
	char id[7];
	char name[9];
	int grade;
};
bool comp1(const stuInfo &a, const stuInfo &b)
{
	return strcmp(a.id, b.id)<0;
}
bool comp2(const stuInfo &a, const stuInfo &b)
{
	if (strcmp(a.name, b.name) < 0)
		return true;
	else if (strcmp(a.name, b.name) == 0 && strcmp(a.id, b.id) < 0)
		return true;
	else
		return false;
}
bool comp3(const stuInfo &a, const stuInfo &b)
{
	if (a.grade < b.grade)
		return true;
	else if (a.grade == b.grade&&strcmp(a.id, b.id)<0)
		return true;
	else
		return false;
}
int main()
{
	int n, c;
	scanf("%d%d", &n, &c);
	stuInfo *stus = new stuInfo[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%s%s%d", stus[i].id, stus[i].name, &stus[i].grade);	
	}
	if (c == 1)
	{
		sort(stus, stus+n, comp1);
	}
	else if (c == 2)
	{
		sort(stus, stus+n, comp2);
	}
	else if (c == 3)
	{
		sort(stus, stus+n, comp3);
	}
	for (int i = 0; i < n; i++)
	{
		printf("%s %s %d\n", stus[i].id, stus[i].name, stus[i].grade);
	}
	delete[]stus;
	stus = NULL;
	return 0;
}