#include <bits/stdc++.h>
using namespace std;

int G, P;

int parent[100001];

int find_root(int x)
{
    if (parent[x] != x) parent[x] = find_root(parent[x]);
    return parent[x];
}

void union_root(int a, int b)
{
    int parentA = find_root(a);
    int parentB = find_root(b);
    
    if (parentA < parentB) parent[parentB] = parentA;
    else parent[parentA] = parentB;
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
        int plane;
        cin >> plane;
        
        int rootPlane = find_root(plane);
        
        // 게이트 자리가 없는 경우
        if (rootPlane == 0) break;
        
        // 게이트 사용 처리
        union_root(rootPlane, rootPlane - 1);
        count++;
    }
    
    cout << count;
}
