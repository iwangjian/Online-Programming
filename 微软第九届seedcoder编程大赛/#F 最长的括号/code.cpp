#include <cstdlib>
#include <iostream>
#include <string>
#include <stack>
using namespace std;
//最长括号匹配问题
int CalculateMaxMatch(string inputStr) 
{
	int length = inputStr.length();
	stack<int> stack;
	int max = 0;
	int start = -1;
	for (int i = 0; i < length; i++) {
		char c = inputStr.at(i);
		//如果是左括号则进栈
		if (c == '(') {
			stack.push(i);
		}
		//右括号则出栈匹配
		else {
			//栈不空的情况下才进行匹配 否则当前的右括号不存在与之匹配的左括号
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
