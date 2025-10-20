#include <bits/stdc++.h>
using namespace std;

int v, e;
int parent[100001];

// 간선의 비용과 연결된 두 노드를 담을 벡터
vector<pair<int, pair<int, int>>> edges;
int minCost;

int findParent(int x)
{
    // 재귀적으로 부모 노드 찾기
    if (parent[x] == x) return x;
    return parent[x] = findParent(parent[x]);
}

void unionParent(int x, int y)
{
    int xRoot = findParent(x);
    int yRoot = findParent(y);
    
    // 루트 노드 변경
    if (xRoot < yRoot) parent[yRoot] = xRoot;
    else parent[xRoot] = yRoot;
}

int main(void) 
{
    cin >> v >> e;
    
    // 부모 테이블 초기화
    for (int i = 0; i < v; i++)
    {
        parent[i] = i;
    }
    
    // 그래프 데이터 초기화
    for (int i = 0; i < e; i++)
    {
        int a, b, cost;
        cin >> a >> b >> cost;
        
        edges.push_back({cost, {a, b}});
    }
    
    // 간선 비용 오름차순 정렬
    sort(edges.begin(), edges.end());
    
    // 최소 신장 트리의 비용 계산
    for (int i = 0; i < e; i++)
    {
        int cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        
        // 사이클 미발생 시 최소 신장 트리에 포함
        if (findParent(a) != findParent(b))
        {
            unionParent(a, b);
            minCost += cost;
        }
    }
    
    cout << minCost;
}
