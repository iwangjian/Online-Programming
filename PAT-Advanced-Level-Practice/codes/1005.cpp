#include<iostream>
#include<string>
using namespace std;
int main()
{
  char s[105];
  int sum = 0;
  string token[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
  while (cin>>s)
  {
    for (int i = 0; s[i]!='\0'; i++)
    {
      sum = sum + s[i] - '0';
    }
    if (sum < 10) {
      cout << token[sum] << endl;
    }
    else if (sum < 100) {
      cout << token[sum / 10] << " " << token[sum % 10] << endl;
    }
    else if (sum < 1000) {
      cout << token[sum / 100] << " " << token[(sum % 100) / 10] << " " << token[sum % 10] << endl;
    }
  }

  return 0;
}