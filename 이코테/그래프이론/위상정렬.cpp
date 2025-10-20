#include <bits/stdc++.h>
using namespace std;

int v, e;

// 진입차수 저장할 배열
int indegree[100001];

// 각 노드에 연결된 간선 데이터를 저장할 리스트
vector<int> graph[100001];

// 위상정렬 결과 저장할 리스트
vector<int> result;

void topologySort()
{
    queue <int> q;

    for (int i = 1; i <= v; i++)
    {
        if (indegree[i] == 0) q.push(i);
    }

    while (!q.empty())
    {
        // 현재 노드 결과 리스트에 추가
        int currentNode = q.front();
        q.pop();
        
        result.push_back(currentNode);
        
        // 연결된 노드의 진입차수 감소
        for (int i = 0; i < graph[currentNode].size(); i++)
        {
            int connectedNode = graph[currentNode][i];
            indegree[connectedNode] -= 1;
            
            // 진입차수가 0인 노드 큐에 추가
            if (indegree[connectedNode] == 0) q.push(connectedNode);
        }
    }
}

int main(void)
{
    cin >> v >> e;
    
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        
        // 그래프와 진입차수 초기화
        graph[a].push_back(b);
        indegree[b]++;
    }
    
    // 위상정렬 수행
    topologySort();
    
    // 결과 출력
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << ' ';
    }
}
