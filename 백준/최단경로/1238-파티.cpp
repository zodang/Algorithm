#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int N, M, X;

vector<int> dijkstra(int start_idx, vector<vector<pair<int, int>>>& arr)
{
    vector<int> dp(N+1);
    for (int i = 1; i <= N; i++)
    {
        dp[i] = INF;
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dp[start_idx] = 0;
    pq.push({0, start_idx});
    
    while (!pq.empty())
    {
        pair<int, int> top_node = pq.top();
        
        int cost = top_node.first;
        int current_idx = top_node.second;
        
        pq.pop();
        
        if (dp[current_idx] < cost) continue;
        
        for (int i = 0; i < arr[current_idx].size(); i++)
        {
            int linked_idx = arr[current_idx][i].first;
            int linked_distance = arr[current_idx][i].second;
            
            if (dp[current_idx] + linked_distance < dp[linked_idx])
            {
                dp[linked_idx] = dp[current_idx] + linked_distance;
                pq.push({dp[linked_idx], linked_idx});
            }
        }
    }
    
    return dp;
}

int main(void)
{
    cin >> N >> M >> X;
    
    vector<vector<pair<int, int>>> arr(N+1);
    vector<vector<pair<int, int>>> reverse_arr(N+1);
    
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        arr[a].push_back({b, c});
        reverse_arr[b].push_back({a, c});
    }
    
    vector<int> from_x = dijkstra(X, arr);
    vector<int> to_x = dijkstra(X, reverse_arr);
    
    vector<int> time_arr(N+1);
    int max_time = 0;
    
    for (int i = 1; i <= N; i++)
    {
        time_arr[i] = from_x[i] + to_x[i];
        max_time = max(max_time, time_arr[i]);
    }
    
    cout << max_time;
}
