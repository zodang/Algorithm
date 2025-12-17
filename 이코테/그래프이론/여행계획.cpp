#include <bits/stdc++.h>
using namespace std;

int N, M;
int graph[201][201];
int parent[201];

int find_parent(int x)
{
    if (parent[x] != x) parent[x] = find_parent(parent[x]);
    return parent[x];
}

void union_parent(int a, int b)
{
    int aRoot = find_parent(a);
    int bRoot = find_parent(b);
    
    if (aRoot < bRoot) parent[bRoot] = aRoot;
    else parent[aRoot] = bRoot;
}

int main() {
    
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
	        graph[i][j] = x; 
	        
	        if (x == 1) union_parent(i, j);
	    }
	}
	
	vector<int> planArr;
	
	for (int i = 0; i < M; i++)
	{
	    int x;
	    cin >> x;
	    planArr.push_back(x);
	}
	
	// 계획 노드의 모든 루트 노드가 동일한지 확인
	int root = find_parent(planArr[0]);
	bool result = 1;
	
	for (int i = 1; i < M; i++)
	{
	    if (find_parent(planArr[i]) != root)
	    {
	        result = 0;
	        break;
	    }
	}
	
	if (result == 0) cout << "NO";
	else cout << "YES";
}
