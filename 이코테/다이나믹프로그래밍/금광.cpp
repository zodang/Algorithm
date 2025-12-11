#include <bits/stdc++.h>
using namespace std;

int T;

int main(void)
{
    cin >> T;
    
    for (int i = 0; i < T; i++)
    {
        int n = 0;
        int m = 0;
        cin >> n >> m;
        
        // 금광 정보 입력
        vector<vector<int>> arr(n + 1, vector<int>(m + 1, 0));
        
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                int x;
                cin >> x;
                arr[i][j] = x;
            }
        }
        
        // dp 테이블 갱신
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
        for (int j = 1; j <= m; j++)
        {
            for (int i = 1; i <= n; i++)
            {
                int prev = 0;
                
                if (i-1 >= 1) prev = max(dp[i-1][j-1], prev);
                if (i+1 <= n) prev = max(dp[i+1][j-1], prev);
                prev = max(dp[i][j-1], prev);
                
                dp[i][j] = arr[i][j] + prev;
            }
        }
        
        // m번째 칸에서의 최대값 계산
        int max_gold = 0;
        
        for (int i = 1; i <= n; i++)
        {
            max_gold = max(dp[i][m], max_gold);
        }
        
        cout << max_gold << '\n';
    }
}
