#include <bits/stdc++.h>
using namespace std;

int m, n;
int parent[200001];

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
    cin >> m >> n;
    
    for (int i = 0; i < m; i++)
	{
	    parent[i] = i;
	}
	
	int max_cost = 0;
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	
	for (int i = 0; i < n; i++)
	{
	    int a, b, c;
	    cin >> a >> b >> c;
	    pq.push({c, {a, b}});
	    
	    max_cost += c;
	}
	
	int min_cost = 0;
    while (!pq.empty())
    {
        pair<int, pair<int, int>> top_node = pq.top();
        
        int node1 = top_node.second.first;
        int node2 = top_node.second.second;
        
        if (FindParent(node1) != FindParent(node2))
        {
            UnionParent(node1, node2);
            
            int cost = top_node.first;
            min_cost += cost;
        }
        
        pq.pop();
    }
    
    cout << max_cost - min_cost << '\n';
}
