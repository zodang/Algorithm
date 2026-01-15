#include <bits/stdc++.h>
using namespace std;

int N, M;

vector<vector<int>> graph;
bool visited[101];

void dfs(int start)
{
    stack<int> s;
    s.push(start);
    visited[start] = true;
    
    while (!s.empty())
    {
        int current = s.top();
        s.pop();
        
        for (int i = 0; i < graph[current].size(); i++)
        {
            int near = graph[current][i];
            if (visited[near]) continue;
            
            s.push(near);
            visited[near] = true;
        }
    }
}

int main(void)
{
    cin >> N;
    cin >> M;
    
    graph.resize(N+1);
    
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    dfs(1);
    
    int count = 0; 
    for (int i = 2; i <= N; i++)
    {
        if (visited[i]) count++;
    }
    
    cout << count;
}
