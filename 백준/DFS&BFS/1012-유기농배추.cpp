#include <bits/stdc++.h>
using namespace std;

int T;
int M, N, K;
int arr[51][51];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void Bfs(int x, int y)
{
    queue<pair<int ,int>> q;
    q.push({x, y});
    
    while (!q.empty())
    {
        pair<int, int> current_node = q.front();
        q.pop();
        
        int cx = current_node.first;
        int cy = current_node.second;
        
        for (int d = 0; d < 4; d++)
        {
            int nx = cx + dx[d];
            int ny = cy + dy[d];
            
            if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
            if (arr[nx][ny] == 0) continue;
            
            arr[nx][ny] = 0;
            q.push({nx, ny});
        }
    }
}

int main() {
	cin >> T;
	
	for (int t = 0; t < T; t++)
	{
	    cin >> M >> N >> K;
	    
	    for (int i = 0; i < M; i++)
	    {
	        for (int j = 0; j < N; j++)
	        {
	            arr[i][j] = 0;
	        }
	    }
	    
	    for (int i = 0; i < K; i++)
	    {
	        int m, n;
	        cin >> m >> n;
	        arr[m][n] = 1;
	    }
	
	    int count = 0;
    	for (int i = 0; i < M; i++)
	    {
	        for (int j = 0; j < N; j++)
	        {
	            if (arr[i][j] != 1) continue;
	            
	            count += 1;
	            Bfs(i, j);
	        }
	    }
	    cout << count << '\n';
	}
}
