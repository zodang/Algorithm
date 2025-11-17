#include <bits/stdc++.h>
using namespace std;

int N, M;

int graph[201][201];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void bfs(int x, int y)
{
    // 큐에 좌표 추가
    queue<pair<int, int>> q;
    q.push({x, y});
    
    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        
        for (int i = 0 ; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            // 갈 수 없는 범위 제외
            if (nx <= 0 || nx > N || ny <= 0 || ny > M) continue;
            if (graph[nx][ny] == 0) continue;
            
            // 처음 방문한 칸 
            if (graph[nx][ny] == 1)
            {
                q.push({nx, ny});
                graph[nx][ny] = graph[cx][cy] + 1;
            }
        }
    }
}

int main() {
	cin >> N >> M;
	
	// 2차원 배열 초기화
	for (int i = 1; i <= N; i++)
	{
	    for (int j = 1; j <= M; j++)
	    {
	        scanf("%1d", &graph[i][j]);
	    }
	}
	
	bfs(1, 1);
	
	cout << graph[N][M];
}
