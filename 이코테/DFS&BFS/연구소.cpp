#include <bits/stdc++.h>
using namespace std;

int N, M;
int graph[8][8];
int tempGraph[8][8];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int maxCount;

void virus(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if (tempGraph[nx][ny] == 1 || tempGraph[nx][ny] == 2) continue;
        
        if (tempGraph[nx][ny] == 0) 
        {
            tempGraph[nx][ny] = 2;
            virus(nx, ny);
        }
    }
    
}

int getCurrentCount()
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (tempGraph[i][j] == 0) count++;
        }
    }
    
    return count;    
}

void dfs(int count)
{
    if (count == 3)
    {
        // 임시 벽 그래프 초기화
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                tempGraph[i][j] = graph[i][j];
            }
        }
        
        // 임시 벽 그래프에서 바이러스 이동
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (tempGraph[i][j] == 2)
                {
                    virus(i, j);
                }
            }
        }
        
        // 빈 칸 최대 개수 갱신
        maxCount = max(maxCount, getCurrentCount());
        return;
    }
    
    // 추가 벽 3개 될 때까지 추가
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (graph[i][j] == 0)
            {
                graph[i][j] = 1;
                count++;
                dfs(count);
                
                graph[i][j] = 0;
                count--;
            }
        }
    }
}

int main() {
	cin >> N >> M;
	
	// 원본 그래프 초기화
	for (int i = 0; i < N; i++)
	{
	    for (int j = 0; j < M; j++)
	    {
	        int x;
	        cin >> x;
	        graph[i][j] = x;
	    }
	}
	
	dfs(0);

    cout << maxCount;
}
