#include <bits/stdc++.h>
using namespace std;

int N, M;
int parent[201];
vector<int> plans;

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
    cin >> M;
    
    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }
    
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int x;
            cin >> x;
            
            if (x == 1) UnionParent(i, j);
        }
    }
    
    for (int i = 0; i < M; i++)
    {
        int p;
        cin >> p;
        
        plans.push_back(p);
    }
    
    int root_plan = FindParent(plans[0]);
    
    for (int i = 1; i < M; i++)
    {
        if (FindParent(plans[i]) != root_plan)
        {
            cout << "NO";
            return 0;
        }
    }
    
    cout << "YES";
}
