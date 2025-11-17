#include <bits/stdc++.h>
using namespace std;

int N, M;
int graph[1001][1001];

void dfs(int x, int y)
{
    if (x < 0 || x >= N || y < 0 || y >= M) return;
    if (graph[x][y] == 0)
    {
        // 방문 처리
        graph[x][y] = 1;
        
        dfs(x - 1, y);
        dfs(x + 1, y);
        dfs(x, y - 1);
        dfs(x, y + 1);
    }
}

int main() {
	cin >> N >> M;
	
	// 2차원 배열 초기화
	for (int i = 0; i < N; i++)
	{
	    for (int j = 0; j < M; j++)
	    {
	        scanf("%1d", &graph[i][j]);
	    }
	}
    
    
    int totalCount = 0;
    
    for (int i = 0; i < N; i++)
	{
	    for (int j = 0; j < M; j++)
	    {
	        if (graph[i][j] == 0)
	        {
	            dfs(i, j);
	            totalCount++;
	        }
	    }
	}
	
	cout << totalCount;
}
