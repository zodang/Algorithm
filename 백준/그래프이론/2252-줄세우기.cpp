#include <bits/stdc++.h>
using namespace std;

int M, N;
int degree[32001];

int main() {
    cin >> N >> M;
    vector<vector<int>> arr(N+1);
    
    for (int m = 0; m < M; m++)
    {
        int a, b;
        cin >> a >> b;
        
        arr[a].push_back(b);
        degree[b] += 1;
    }
    
    // 진입차수가 0인 노드 큐에 추가
    queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        if (degree[i] == 0) q.push(i);
    }
    
    // 위상정렬 수행
    vector<int> result;
    while (!q.empty())
    {
        int current_node = q.front();
        q.pop();
        
        result.push_back(current_node);
        
        for (int i = 0; i < arr[current_node].size(); i++)
        {
            int linked_node = arr[current_node][i];
            degree[linked_node] -= 1;
            
            if (degree[linked_node] == 0)
            {
                q.push(linked_node);
            }
        }
    }
    
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << ' ';
    }
}
