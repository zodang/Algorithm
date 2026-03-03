#include <bits/stdc++.h>
using namespace std;

int N, M, V;
bool visited[1001];

vector<int> DFS(const vector<vector<int>>& graph, int start_idx)
{
    fill_n(visited, N+1, 0);
    
    vector<int> result;
    stack<int> s;
    
    s.push(start_idx);
    
    while (!s.empty())
    {
        int current_node = s.top();
        s.pop();
        
        if (visited[current_node]) continue;
        
        visited[current_node] = true;
        result.push_back(current_node);
        
        for (int i = graph[current_node].size()-1; i >= 0; i--)
        {
            int linked_node = graph[current_node][i];
            
            if (visited[linked_node] == false)
            {
                s.push(linked_node);
            }
        }
    }
    
    return result;
}

vector<int> BFS(const vector<vector<int>>& graph, int start_idx)
{
    fill_n(visited, N+1, 0);
    
    vector<int> result;
    queue<int> q;
    
    q.push(start_idx);
    visited[start_idx] = true;
    result.push_back(start_idx);
    
    while (!q.empty())
    {
        int current_node = q.front();
        q.pop();
        
        for (int i = 0; i < graph[current_node].size(); i++)
        {
            int linked_node = graph[current_node][i];
            
            if (visited[linked_node] == false)
            {
                q.push(linked_node);
                visited[linked_node] = true;
                result.push_back(linked_node);
            }
        }
    }
    
    return result;
}

int main() {
    cin >> N >> M >> V;
    vector<vector<int>> graph(N+1);
    
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    for (int i = 0; i <= N; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }
    
    vector<int> dfs_result = DFS(graph, V);
    for (int i = 0; i < dfs_result.size(); i++)
    {
        cout << dfs_result[i] << ' ';
    }
    
    cout << '\n';
    
    vector<int> bfs_result = BFS(graph, V);
    for (int i = 0; i < bfs_result.size(); i++)
    {
        cout << bfs_result[i] << ' ';
    }
}
