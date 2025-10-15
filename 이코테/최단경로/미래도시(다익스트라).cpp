#include <bits/stdc++.h>
using namespace std;

int const INF = 1e9;

int N, M;
int X, K;

vector<pair<int, int>> graph[101];
int d[101];

void dijkstra(int start)
{
    // {cost, index}
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
    // 전체 회사 개수, 경로의 개수 초기화
    cin >> N >> M;
    
    // 그래프 초기화
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back({b, 1});
        graph[b].push_back({a, 1});
    }
    
    // 판매 회사, 소개팅 상대 회사
    cin >> X >> K;
    
    int costX, costK = 0;
    int cost = -1;

    // 1번부터 K번까지의 경로 계산
    fill_n(d, 101, INF);
    dijkstra(1);
    
    if (d[K] == INF)
    {
        cout << cost;
        return 0;
    }
    else
    {
        costK = d[K];
    }
    
    // K번부터 X번까지의 경로 계산
    fill_n(d, 101, INF);
    dijkstra(K);
    
    if (d[X] == INF)
    {
        cout << cost;
        return 0;
    }
    else
    {
        costX = d[X];
    }
    
    cost = costK + costX; 
    cout << cost;
}
