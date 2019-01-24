#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int cnt_max(int m)
{
    if(m > 1){
        return m;
    }
    else{
        return 1;
    }
}
int main() {
    
    int cell[200][200];
    int r, c;
    cin>>r>>c;
    for(int i=0; i<r; i++){
        for(int j=0;j<c;j++){
            cin>>cell[i][j];
        }
    }
    int row = r;
    int col = c;
    int dp[row--][col--];
    dp[row][col] = 1;
    for(int j=col-1; j>=0; j--){
        dp[row][j] = cnt_max(dp[row][j+1]-cell[row][j]);
    }
    for(int i=row-1; i>=0; i--){
        dp[i][col] = cnt_max(dp[i+1][col]-cell[i][col]);
        for(int j=col-1; j>=0; j--){
            int right = cnt_max(dp[i][j+1]-cell[i][j]);
            int bottom = cnt_max(dp[i+1][j]-cell[i][j]);
            dp[i][j] = min(right, bottom);
        }
    }
    cout<<dp[0][0]<<endl;
    
    return 0;
}