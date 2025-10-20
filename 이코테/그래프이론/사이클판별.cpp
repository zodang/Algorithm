#include <bits/stdc++.h>
using namespace std;

int v, e;
int parent[100001];

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

int main() 
{
    cin >> v >> e;
    
    // 부모 테이블 초기화
    for (int i = 0; i < v; i++)
    {
        parent[i] = i;
    }
    
    // 사이클 검사
    bool hasCycle = false;
    
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        
        if (findParent(a) == findParent(b)) 
        {
            hasCycle = true;
            break;
        }
        else
        {
            unionParent(a, b);
        }
    }
    
    if (hasCycle) cout << "사이클이 발생합니다.";
    else cout << "사이클이 존재하지 않습니다.";
}
