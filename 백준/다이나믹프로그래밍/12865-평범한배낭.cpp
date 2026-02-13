#include <bits/stdc++.h>
using namespace std;

int N, K;
int k_arr[101];
int v_arr[101];
int dp[101][100001];

int main() {
    cin >> N >> K;
    
    for (int i = 1; i <= N; i++)
    {
        cin >> k_arr[i] >> v_arr[i];
    }

    for (int i = 1; i <= N; i++)
    {
        for (int k = 0; k <= K; k++)
        {
            // dp[i][k] : i번째 물건까지 고려했을 때 무게 k 이하에서의 최대 가치
            dp[i][k] = dp[i-1][k];
            
            int left_k = k - k_arr[i];
            if (left_k >= 0)
            {
                dp[i][k] = max(dp[i][k], dp[i-1][left_k] + v_arr[i]);
            }
        }
    }
    
    cout << dp[N][K];
}
