#include <bits/stdc++.h>
using namespace std;

int v, e, start;
vector<pair<int, int>> graph[100001];
bool visited[100001];
int d[100001];

const int INF = 1e9;

int getSmallestNode()
{
    int min_value = INF;
    int index = -1;
    
    for (int i = 1; i <= v; i++)
    {
        // 방문하지 않은 노드 중 최단거리 노드의 인덱스
        if (!visited[i] && d[i] < min_value)
        {
            min_value = d[i];
            index = i;
        }
    }
    
    return index;
}

void dijkstra(int start)
{
    // 시작노드와 연결된 노드의 최단거리 초기화
    d[start] = 0;
    visited[start] = true;
    for (int i = 0; i < graph[start].size(); i++)
    {
        d[graph[start][i].first] = graph[start][i].second;
    }
    
    // 나머지 노드의 최단거리
    for (int i = 0; i < v- 1; i++)
    {
        int now = getSmallestNode();
        visited[now] = true;
        
        for (int j = 0; j < graph[now].size(); j++)
        {
            int cost = d[now] + graph[now][j].second;
            if (cost < d[graph[now][j].first])
            {
                // 연결된 노드의 최단거리 갱신
                d[graph[now][j].first] = cost;
                
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
    for (int i = 1 ; i <= v; i++)
    {
        if (d[i] == INF) cout << "INF" << '\n';
        else cout << d[i] << '\n';
    }
}
