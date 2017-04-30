#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
#define MAX 51
#define MOD 101
//构造矩阵，使用矩阵快速幂
//时间复杂度O( n^2 * log(k) )
struct Matrix {
	int n, m;
	int a[MAX][MAX];
	void clear() {
		n = m = 0;
		for (int i = 0; i < MAX; i++)
			for (int j = 0; j < MAX; j++)
				a[i][j] = 0;
	}
	Matrix operator +(const Matrix &b)const {
		Matrix tmp;
		tmp.n = n;
		tmp.m = m;
		for (int i = 0; i<n; i++)
			for (int j = 0; j<m; j++)
				tmp.a[i][j] = (a[i][j] + b.a[i][j]) % MOD;
		return tmp;
	}
	Matrix operator *(const Matrix &b)const {
		Matrix tmp;
		tmp.clear();
		tmp.n = n;
		tmp.m = b.m;
		for (int i = 0; i<n; i++)
			for (int j = 0; j<b.m; j++)
				for (int k = 0; k<m; k++)
					tmp.a[i][j] = (tmp.a[i][j] + a[i][k] * b.a[k][j]) % MOD;
		return tmp;
	}
	void print(){
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<m - 1; j++)
				cout << a[i][j] << " ";
			cout << a[i][m - 1] << endl;
		}
	}
	Matrix operator ^(int k)const {
		Matrix tmp, mul;
		tmp.clear();
		mul.clear();
		mul.n = mul.m = tmp.m = tmp.n = n;
		mul = mul + (*this);
		for (int i = 0; i<n; i++)
			tmp.a[i][i] = 1;
		while (k>0) {
			if (k & 1) {
				tmp = tmp*mul;
			}
			k >>= 1;
			mul = mul*mul;
		}
		return tmp;
	}
	Matrix transpose() {
		Matrix tmp;
		tmp.n = m;
		tmp.m = n;
		for (int i = 0; i<n; i++)
			for (int j = 0; j<m; j++)
				tmp.a[j][i] = a[i][j];
		return tmp;
	}
};

int main() 
{
	int n, k;
	while (cin>>n>>k)
	{
		if (n == 0 && k == 0) {
			return 0;
		}
		Matrix arr;
		arr.m = 1;
		arr.n = n;
		for (int i = 0; i<n; i++)
			cin >> arr.a[i][0];
		Matrix mul;
		mul.clear();
		mul.n = mul.m = n;
		for (int i = 0; i<n; i++) {
			mul.a[i][i] = 1;
			mul.a[i][(i + 1) % n] = 1;
		}
		arr = (mul^k)*arr;
		arr.transpose().print();
	}	
}