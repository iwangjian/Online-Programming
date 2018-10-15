#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct node
{
	int left;
	int right;
};
node tree[32];
int build_tree(int post[], int in[], int n)
{
	if (n <= 0) {
		return -1;
	}
	int root = post[n - 1];
	tree[root].left = -1;
	tree[root].right = -1;
	int i = 0;
	while (i < n)
	{
		if (in[i] == root)
			break;
		i++;
	}
	tree[root].left = build_tree(post, in, i);
	tree[root].right = build_tree(post + i, in + i + 1, n - i - 1);
	return root;
}

int main()
{
	int n;
	cin >> n;
	int post[30], in[30];
	for (int i = 0; i < n; i++)
	{
		cin >> post[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> in[i];
	}
	queue<int> q;
	vector<int> vec;
	int root = build_tree(post, in, n);
	q.push(root);
	while (!q.empty())
	{
		int head = q.front();
		vec.push_back(head);
		q.pop();
		if (tree[head].left != -1) {
			q.push(tree[head].left);
		}
		if (tree[head].right != -1) {
			q.push(tree[head].right);
		}
	}
	for (int i = 0; i < n-1; i++)
	{
		cout << vec[i] << " ";
	}
	cout << vec[n - 1] << endl;
	return 0;
}