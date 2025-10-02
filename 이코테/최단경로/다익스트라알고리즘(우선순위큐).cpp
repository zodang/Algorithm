#include <bits/stdc++.h>
using namespace std;

int v, e, start;
vector<pair<int, int>> graph[100001];
int d[100001];

const int INF = 1e9;

void dijkstra(int start)
{
    // 우선순위 큐 <cost, index>
    priority_queue<pair<int, int>> pq;
    
    // 시작 노드 큐에 추가
    pq.push({0, start});
    d[start] = 0;
    
    while (!pq.empty())
    {
        // 최소값부터 나오게 하도록 음수값으로 넣어뒀기 때문에 음수값으로 pop
        int dist = -pq.top().first;
        
        // index이기 때문에 양수 그대로 사용
        int now = pq.top().second;
        
        pq.pop();
        
        // 이미 최단거리인 경우 무시
        if (d[now] < dist) continue;
        
        for (int i = 0; i < graph[now].size(); i++)
        {
            // 현재 노드를 거치는 거리
            int cost = dist + graph[now][i].second;
            
            // 연결된 노드의 최단거리 갱신
            if (cost < d[graph[now][i].first])
            {
                d[graph[now][i].first] = cost;
                
                // 최소값부터 나오게 하도록 음수값으로 push
                pq.push({-cost, graph[now][i].first});
            }
        }
    }
}

int main(void) 
{
    // 노드 개수, 간선 개수, 시작노드 인덱스
    cin >> v >> e >> start;
    
    // 그래프 초기화
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        
        // a 노드에서 b 노드까지의 c만큼의 비용
        graph[a].push_back({b, c});
    }
    
    // 배열 d의 100001개 요소를 INF로 초기화
    fill_n(d, 100001, INF);
    
    dijkstra(start);
    
    // 시작노드로부터 모든 노드까지의 최단거리 출력
    for (int i = 1; i <= v; i++)
    {
        if (d[i] == INF) cout << "INF" << '\n';
        else cout << d[i] << '\n';
    }
}
