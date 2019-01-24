#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define Rep(i, n) for(int i = 1; i <= n; ++i)
typedef long long LL;
typedef unsigned long long ULL;

const int INF = 0x3f3f3f3f;
const int N = 200;

unordered_map<ULL, int> mp;
int board[25][25], init[25][25];
int checkNeighbor(int x, int y, int row, int col)
{
        int count = 0;
        for (int i = x - 1; i <= x + 1; ++i)
        {
            for (int j = y - 1; j <= y + 1; ++j)
            {
                if (i == x && j == y){
                    continue;
                }
                else if(i<0 && j<0){
                    if(board[row-1][col-1] == 1 || board[row-1][col-1] == 2){
                        count++;
                    }
                }
                else if(i<0 && j>=0){
                    if(j==col){
                        if(board[row-1][0] == 1 || board[row-1][0] == 2){
                           count++;
                        }
                    }
                    else{
                        if(board[row-1][j] == 1 || board[row-1][j] == 2){
                           count++;
                        }
                    }
                }
                else if(i>=0 && j<0){
                    if(i==row){
                        if(board[0][col-1] == 1 || board[0][col-1] == 2)
                        count++;
                    }
                    else{
                        if(board[i][col-1] == 1 || board[i][col-1] == 2)
                        count++;
                    }
                    
                }
                else if(i>=0 && j>=0)
                {
                    if(i==row){
                        if(j==col){
                            if(board[0][0]==1||board[0][0]==2)
                            count++;
                        }
                        else{
                            if(board[0][j]==1||board[0][j]==2)
                            count++;
                        }
                    }
                    else{
                        if(j==col){
                            if(board[i][0]==1||board[i][0]==2)
                            count++;
                        }
                        else{
                            if(board[i][j]==1||board[i][j]==2)
                            count++;
                        }
                    }
                }
            }
        }
        return count;
}
void game(int row ,int col)
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            int sum = checkNeighbor(i, j, row, col);
            if (sum == 2) continue;
            else if(sum == 3){
                board[i][j] = (board[i][j] == 0 ? 3 : 1);
            }
            else{
                board[i][j] = (board[i][j] == 0 ? 0 : 2);
            } 
        }
    }

    for (int i = 0; i < row; ++i){
        for (int j = 0; j < col; ++j){
            board[i][j] %= 2;
        }
    }
} 

ULL f(int n, int m) {
	ULL res = 0;
	rep(i, n) rep(j, m) res = res * 173 + board[i][j];
	return res;
}

int main() {
    int n, m, c;
    cin>>n>>m>>c;
    
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0; j<m; j++){
            if(s[j] == '*'){
                board[i][j] = 1;
            }
            else if(s[j] == '-'){
                board[i][j] = 0;
            }
        }
	}
	memcpy(init, board, sizeof init);
	int pe = 0, start = 0;
    for(int iter=1; iter<=c; iter++){
		game(n, m);
		ULL _ = f(n, m);
		if(mp[_]) {
			start = mp[_];
			pe = iter - start;
			break;
		}
		else mp[_] = iter;
    }
    if(pe) {
		memcpy(board, init, sizeof init);
		int tot = c - start + 1;
		c = tot % pe;
		if(c == 0) c = pe;
		c += start - 1;
		for(int iter=1; iter<=c; iter++){
			game(n, m);
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0;j<m;j++){
			if(board[i][j] == 1){
				cout<<'*';
			}
			else{
				cout<<'-';
			}
		}
		cout<<'\n';
	}
    return 0;
}