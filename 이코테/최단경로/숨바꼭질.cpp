#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int N, M;
vector<vector<int>> graph;
int d[20001];

int main(void)
{
    cin >> N >> M;
    graph.resize(N + 1);
    fill_n(d, N + 1, INF);
    
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    pq.push({0, 1});
    d[1] = 0;
    
    while (!pq.empty())
    {
        int currentCost = pq.top().first;
        int currentIdx = pq.top().second;
        
        pq.pop();
        
        if (d[currentIdx] < currentCost) continue;
        
        for (int i = 0; i < graph[currentIdx].size(); i++)
        {
            int newCost = currentCost + 1;
            
            if (newCost < d[graph[currentIdx][i]])
            {
                d[graph[currentIdx][i]] = newCost;
                pq.push({newCost, graph[currentIdx][i]});
            }
        }
    }
    
    int maxIdx = 0;
    int maxD = 0;
    int count = 0;
    
    for (int i = 1; i <= N; i++)
    {
        if (d[i] > maxD)
        {
            maxIdx = i;
            maxD = d[i];
            count = 1;
        }
        else if (d[i] == maxD) count++;
    }
    
    cout << maxIdx << ' ' << maxD << ' ' << count;
}
