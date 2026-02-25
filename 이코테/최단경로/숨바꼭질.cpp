#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int N, M;

int dp[20001];

int main(void)
{
    cin >> N >> M;
    
    vector<vector<int>> arr(N+1);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    
    for (int i = 1; i <= N; i++)
    {
        dp[i] = INF;
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    pq.push({0, 1});
    dp[1] = 0;
    
    while (!pq.empty())
    {
        pair<int, int> top_node = pq.top();
        pq.pop();
        
        int cost = top_node.first;
        int current_idx = top_node.second;
        
        if (dp[current_idx] < cost) continue;
        
        for (int i = 0; i < arr[current_idx].size(); i++)
        {
            int linked_idx = arr[current_idx][i];
            
            if (dp[current_idx] + 1 < dp[linked_idx])
            {
                dp[linked_idx] = dp[current_idx] + 1;
                pq.push({dp[linked_idx], linked_idx});
            }
        }
    }
    
    int num = 1;
    int distance = dp[1];
    int count = 1;
    
    for (int i = 1; i <= N; i++)
    {
        if (dp[i] > distance)
        {
            num = i;
            distance = dp[i];
            count = 1;
            continue;
        }
        
        if (dp[i] == distance)
        {
            count += 1;
        }
    }
    
    cout << num << ' ' << distance << ' ' << count;
}
