#include <bits/stdc++.h>
using namespace std;

int M, N;
int arr[1001][1001];

queue<pair<int, int>> q;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
	cin >> M >> N;
	
	int max_count = 0;
	int current_count = 0;
	
	for (int i = 0; i < N; i++)
	{
	    for (int j = 0; j < M; j++)
	    {
	        cin >> arr[i][j];
	        
	        if (arr[i][j] == 1)
	        {
	            q.push({i, j});
	            current_count += 1;
	        }
	        if (arr[i][j] != -1) 
	        {
	            max_count += 1;
	        }
	    }
	}
	
	if (current_count == max_count)
	{
	    cout << 0;
	    return 0;
	}
	
	int day_count = 0;
	int total_count = 0;
	
	while (!q.empty())
	{
	    pair<int, int> current_node = q.front();
	    q.pop();
	    total_count += 1;
	    
	    for (int d = 0; d < 4; d++)
	    {
	        int nx = current_node.first + dx[d];
	        int ny = current_node.second + dy[d];
	        
	        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
	        if (arr[nx][ny] != 0) continue;
	        
	        arr[nx][ny] = arr[current_node.first][current_node.second] +  1;
	        day_count = max(day_count, arr[nx][ny]);
	        q.push({nx, ny});
	    }
	}
	
	if (max_count != total_count) cout << -1;
	else cout << day_count-1;
}
