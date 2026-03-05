#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[1001][1001];
bool visited[1001][1001];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void Bfs(pair<int, int> start_pos)
{
    queue<pair<int, int>> q;
    q.push(start_pos);
    arr[start_pos.first][start_pos.second] = 0;
    visited[start_pos.first][start_pos.second] = true;
    
    while (!q.empty())
    {
        pair<int, int> current_node = q.front();
        q.pop();
        
        for (int d = 0; d < 4; d++)
        {
            int nx = current_node.first + dx[d];
            int ny = current_node.second + dy[d];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (arr[nx][ny] == 0) continue;
            if (visited[nx][ny]) continue;
            
            q.push({nx, ny});
            arr[nx][ny] = arr[current_node.first][current_node.second] + 1;
            visited[nx][ny] = true;
        }
    }
}

int main() {
	cin >> n >> m;
	
	pair<int, int> start_pos;
	for (int i = 0; i < n; i++)
	{
	    for (int j = 0; j < m; j++)
	    {
	        cin >> arr[i][j];
	        
	        if (arr[i][j] == 2) start_pos = {i, j};
	    }
	}
	
	Bfs(start_pos);
	
	for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && arr[i][j] == 1) cout << "-1" << ' ';
            else cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}
