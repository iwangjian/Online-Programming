#include <cstdlib>
#include <iostream>
#include <string>
#include <stack>
using namespace std;
//�����ƥ������
int CalculateMaxMatch(string inputStr) 
{
	int length = inputStr.length();
	stack<int> stack;
	int max = 0;
	int start = -1;
	for (int i = 0; i < length; i++) {
		char c = inputStr.at(i);
		//��������������ջ
		if (c == '(') {
			stack.push(i);
		}
		//���������ջƥ��
		else {
			//ջ���յ�����²Ž���ƥ�� ����ǰ�������Ų�������֮ƥ���������
			if (!stack.empty()) {
				stack.pop();
				if (stack.empty()) {
					if (max < i - start)
						max = i - start;
				}
				else {
					int t = stack.top();
					if (max < i - t)
						max = i - t;
				}
			}
			else {
				start = i;
			}
		}
	}
	return max;
}

int main()
{
	string inputStr;
	while (cin >> inputStr)
	{
		cout << CalculateMaxMatch(inputStr) << endl;
	}
	return 0;
}
