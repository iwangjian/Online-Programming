#include <iostream>  
using namespace std;
bool ispreorder(int a[], int len)
{
	if (a == NULL || len <= 0)
		return false;
	int root = a[0];
	int i;
	for (i = 1; i<len; i++)
	{
		if (a[i]>root)
			break;
	}
	int j = i;
	for (; j<len; j++)
	{
		if (a[j]<root)
			return false;
	}
	bool left = true; 
	if (i>1)
		left = ispreorder(a + 1, i - 1); 
	if (!left)
		return false;
	bool right = true;
	if (i<len)
		right = ispreorder(a + i, len - i);  
	return left && right;  
}
int main()
{
	int n, num;
	while (cin >> n)
	{
		int *tree = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> num;
			tree[i] = num;
		}
		if (n == 1) {
			cout << "true" << endl;
		}
		else if (ispreorder(tree, n)) {
			cout << "true" << endl;
		}
		else {
			cout << "false" << endl;
		}
		delete[]tree;
		tree = NULL;
	}
}