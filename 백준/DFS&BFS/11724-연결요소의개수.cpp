#include <bits/stdc++.h>
using namespace std;

int N, M;

int visited[1001];
vector<vector<int>> arr;

void Dfs(int current_node)
{
    visited[current_node] = true;
    
    for (int i = 0; i < arr[current_node].size(); i++)
    {
        int linked_node = arr[current_node][i];
        if (!visited[linked_node])
        {
            visited[linked_node] = true;
            Dfs(linked_node);
        }
    }
}

int main(void)
{
    cin >> N >> M;
    arr.resize(N+1);
    
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        
        // 양방향 그래프
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    
    int count = 0;

    for (int i = 1; i <= N; i++)
    {
        if (visited[i]) continue;
        
        Dfs(i);
        count += 1;
    }
    
    cout << count;
}
