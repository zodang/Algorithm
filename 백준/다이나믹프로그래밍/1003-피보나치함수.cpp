#include <bits/stdc++.h>
using namespace std;

int T;
pair<int, int> dp[41];

pair<int, int> Fibonacci(int n)
{
    if (n == 0 || n == 1) return dp[n];
    
    for (int i = 2; i <= n; i++)
    {
        dp[i].first = dp[i-1].first + dp[i-2].first;
        dp[i].second = dp[i-1].second + dp[i-2].second;
    }
    
    return dp[n];
}

int main(void) {
    cin >> T;
    
    dp[0] = {1, 0};
    dp[1] = {0, 1};
    
    for (int t = 0; t < T; t++)
    {
        int n;
        cin >> n;
        pair<int ,int> result = Fibonacci(n);
        
        cout << result.first << ' ' << result.second << '\n';
    }
}
