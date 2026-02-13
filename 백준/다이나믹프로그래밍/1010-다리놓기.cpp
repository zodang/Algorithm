#include <bits/stdc++.h>
using namespace std;

int T;
int dp[30][30];

int main(){
    cin >> T;
    
    for (int i = 0; i < 30; i++)
    {
        dp[i][i] = 1;
        dp[0][i] = 1;
    }
    
    for (int i = 1; i < 30; i++)
    {
        for (int j = i+1; j < 30; j++)
        {
            dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
        }
    }
    
    for (int i = 0; i < T; i++)
    {
        int N, M;
        cin >> N >> M;
        cout << dp[N][M] << '\n';
    }
}
