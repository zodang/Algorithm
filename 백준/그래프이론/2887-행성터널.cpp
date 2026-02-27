#include <bits/stdc++.h>
using namespace std;
int N;

vector<pair<int, int>> x_pos;
vector<pair<int, int>> y_pos;
vector<pair<int, int>> z_pos;

vector<pair<int, pair<int, int>>> edges;
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

int main(void)
{
    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        parent[i] = i;
    }
    
    for (int i = 0; i < N; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        
        x_pos.push_back({x, i});
        y_pos.push_back({y, i});
        z_pos.push_back({z, i});
    }

    sort(x_pos.begin(), x_pos.end());
    sort(y_pos.begin(), y_pos.end());
    sort(z_pos.begin(), z_pos.end());
    
    for (int i = 1; i < N; i++)
    {
        edges.push_back({abs(x_pos[i].first - x_pos[i - 1].first), {x_pos[i].second, x_pos[i - 1].second}});
        edges.push_back({abs(y_pos[i].first - y_pos[i - 1].first), {y_pos[i].second, y_pos[i - 1].second}});
        edges.push_back({abs(z_pos[i].first - z_pos[i - 1].first), {z_pos[i].second, z_pos[i - 1].second}});
    }
    
    sort(edges.begin(), edges.end());
    
    int count = 0;
    int min_cost = 0;
    
    for (int i = 0; i < edges.size(); i++)
    {
        int node1 = edges[i].second.first;
        int node2 = edges[i].second.second;
        
        if (FindParent(node1) != FindParent(node2))
        {
            UnionParent(node1, node2);
            
            min_cost += edges[i].first;
            count += 1;
        }
    }
    
    cout << min_cost;
}
