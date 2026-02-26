#include <bits/stdc++.h>
using namespace std;

int N, M;
int parent[100001];

int FindParent(int x)
{
    if (parent[x] != x) parent[x] = FindParent(parent[x]);
    return parent[x];
}

void UnionParent(int x, int y)
{
    int root_x = FindParent(x);
    int root_y = FindParent(y);
    
    if (root_x < root_y) parent[root_y] = root_x;
    else parent[root_x] = root_y;
}

int main() {
    cin >> N >> M;
    
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        
        pq.push({c, {a, b}});
    }
    
    for (int i = 1; i <= N; i++) 
    {
        parent[i] = i;
    }
    
    int sum_cost = 0;
    int max_cost = 0;
    
    while (!pq.empty())
    {
        pair<int, pair<int, int>> node = pq.top();
        
        int node1 = node.second.first;
        int node2 = node.second.second;
        
        // 사이클이 생기지 않는다면 (부모가 다르다면) 비용 합산
        if (FindParent(node1) != FindParent(node2))
        {
            UnionParent(node1, node2);
            
            int cost = node.first;
            sum_cost += cost;
            max_cost = max(max_cost, cost);
        }
        
        pq.pop();
    }
    
    cout << sum_cost - max_cost;
}
