#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int, int>> arr;

int main(void)
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int t;
        int p;
        cin >> t >> p;
        
        arr.push_back(make_pair(t, p));
    }
    
    vector<int> dp(N + 1, 0);
    int maxP = 0;
    
    for (int i = N - 1; i >= 0; i--)
    {
        int nextIdx = i + arr[i].first;
        
        if (nextIdx <= N) 
        {
            dp[i] = max(maxP, arr[i].second + dp[nextIdx]);
            maxP = dp[i];
        }
        
        else dp[i] = maxP;
    }
    
    cout << maxP;
}
