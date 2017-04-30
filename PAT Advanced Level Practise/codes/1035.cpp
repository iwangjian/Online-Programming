#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	cin >> n;
	string *name = new string[n];
	string *psw = new string[n];
	for (int i = 0; i < n; i++)
	{
		cin >> name[i] >> psw[i];
	}

	int account = 0;
	for (int i = 0; i < n;i++)
	{
		char password[11];
		bool modified = false;
		int len = psw[i].length();
		for (int j = 0;j < len;j++)
		{
			password[j] = psw[i].at(j);
		}
		for (int j = 0; j < len; j++)
		{
			if (password[j] == '1') {
				password[j] = '@';
				modified = true;
			}
			else if (password[j] == '0') {
				password[j] = '%';
				modified = true;
			}
			else if (password[j] == 'l') {
				password[j] = 'L';
				modified = true;
			}
			else if (password[j] == 'O') {
				password[j] = 'o';
				modified = true;
			}
		}
		if (modified)
		{
			password[len] = '\0';
			psw[i] = password;
			account++;
		}
		else {
			psw[i] = "0";
		}
	}

	if (account == 0&& n==1) {
		cout << "There is 1 account and no account is modified" << endl;
	}
	else if (account == 0 && n > 1) {
		cout << "There are " << n << " accounts and no account is modified" << endl;
	}
	else if (account > 0) {
		cout << account << endl;
		for (int i = 0;i < n;i++)
		{
			if (psw[i] != "0") {
				cout << name[i] << " " << psw[i] << endl;
			}
		}
	}
	return 0;
}