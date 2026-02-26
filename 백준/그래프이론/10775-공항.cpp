#include <bits/stdc++.h>
using namespace std;

int G, P;
vector<int> planes;
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
    cin >> G;
    cin >> P;
    
    for (int i = 0; i <= G; i++)
    {
        parent[i] = i;
    }
    
    int count = 0;
    
    for (int i = 0; i < P; i++)
    {
        int p;
        cin >> p;
        
        int root_node = FindParent(p);
        
        if (root_node == 0) break;
        else
        {
            UnionParent(root_node, root_node-1);
            count++;
        }
    }
    
    cout << count;
}
