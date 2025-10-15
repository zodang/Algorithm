#include <bits/stdc++.h>
using namespace std;

int const INF = 1e9;

// 도시개수, 통로 개수, 시작 인덱스
int N, M, C;

// 도시 정보를 담는 그래프 {index, cost}
vector<pair<int, int>> graph[30001];

// 시작 노드부터 모든 노드까지의 최단거리 테이블
int d[30001];

void dijkstra(int start)
{
    // {비용, 도착 노드}
    priority_queue<pair<int, int>> pq;
    
    // 시작 노드 초기화
    pq.push({0, start});
    d[start] = 0;
    
    while (!pq.empty())
    {
        int currentCost = -pq.top().first;
        int currentIndex = pq.top().second;
        
        pq.pop();
        
        if (d[currentIndex] < currentCost) continue;
        
        // 현재 노드를 거쳐갈 때의 최단 경로 갱신
        for (int i = 0; i < graph[currentIndex].size(); i++)
        {
            // graph[currentIndex][i]는 현재 노드와 연결된 인접노드
            int newCost = currentCost + graph[currentIndex][i].second;
            
            if (newCost < d[graph[currentIndex][i].first])
            {
                d[graph[currentIndex][i].first] = newCost;
                pq.push({-newCost, graph[currentIndex][i].first});
            }
        }
    }
}

int main(void)
{
    cin >> N >> M >> C;
    
    // 도시 정보 초기화
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    
    fill_n(d, 30001, INF);
    
    dijkstra(C);
    
    // 연결된 도시 개수, 최단거리 중 가장 큰 값
    int rCount = N - 1;
    int rTime = 0;
    
    for (int i = 1; i <= N; i++)
    {
        if (d[i] == INF) rCount--;
        if (rTime < d[i]) rTime = d[i];
    }
    
    // 결과 출력
    cout << rCount << ' ' << rTime;
}
