#include <bits/stdc++.h>
using namespace std;

int n;
int arr[501][501];
int dp[501][501];

int main() {
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int x = 0;
            cin >> x;
            arr[i][j] = x;
            dp[i][j] = 0;
        }
    }
    
    dp[0][0] = arr[0][0];
    
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            // 점화식: 왼쪽 위, 위 방향 요소 중 최대값 비교
            if (j-1 < 0) dp[i][j] = dp[i-1][j] + arr[i][j];
            else if (j == i) dp[i][j] = dp[i-1][j-1] + arr[i][j];
            else dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + arr[i][j];
        }
    }
    
    int max_sum = 0;
    for (int i = 0; i < n; i++)
    {
        max_sum = max(max_sum, dp[n-1][i]);
    }
    
    cout << max_sum;
}
