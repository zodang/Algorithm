#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n = 0;
    cin >> n;
    
    vector<vector<int>> arr(n, vector<int>(n, 0));
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            int x;
            cin >> x;
            arr[i][j] = x;
        }
    }
    
    dp[0][0] = arr[0][0];
    
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            int max_prev = 0;
            
            // 왼쪽 위의 값을 더하는 경우
            if (j-1 >= 0) max_prev = max(max_prev, dp[i-1][j-1]);
            
            // 바로 위의 값을 더하는 경우
            max_prev = max(max_prev, dp[i-1][j]);
            
            dp[i][j] = max_prev + arr[i][j];
        }
    }
    
    int max_sum = 0;
    
    for (int i = 0; i < n; i++)
    {
        max_sum = max(max_sum, dp[n-1][i]);
    }
    
    cout << max_sum;
    
}
