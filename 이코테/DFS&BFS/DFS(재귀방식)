# include <bits/stdc++.h>

using namespace std;

bool visited[9];
vector<int> graph[9];

void dfs(int x)
{
    // 현재 노드 방문 처리
    visited[x] = true;
    cout << x << ' ';
    
    for (int i = 0; i < graph[x].size(); i++)
    {
        // 현재 노드와 연결된 노드
        int y = graph[x][i];
        
        // 방문하지 않은 노드를를 재귀적으로 방문
        if (!visited[y])
        {
            dfs(y);
        }
    }
}


int main(void)
{
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(8);
    
    graph[2].push_back(1);
    graph[2].push_back(7);
    
    graph[3].push_back(1);
    graph[3].push_back(4);
    graph[3].push_back(5);
    
    graph[4].push_back(3);
    graph[4].push_back(5);
    
    graph[5].push_back(3);
    graph[5].push_back(4);
    
    graph[6].push_back(7);
    
    graph[7].push_back(2);
    graph[7].push_back(6);
    graph[7].push_back(8);
    
    graph[8].push_back(1);
    graph[8].push_back(7);
    
    dfs(1);
}
