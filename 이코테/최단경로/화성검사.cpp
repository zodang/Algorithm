#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int T;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
	cin >> T;
	
	for (int i = 0; i < T; i++)
	{
	    int N;
	    cin >> N;
	    
	    int graph[N][N];
	    int d[N][N];
	    
	    for (int i = 0; i < N; i++)
	    {
	        fill_n(d[i], N, INF);
	    }
	    
	    for (int j = 0; j < N; j++)
	    {
	        for (int k = 0; k < N; k++)
	        {
	            int cost;
	            cin >> cost;
	            
	            graph[j][k] = cost;
	        }
	    }
	    
	    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	    
	    d[0][0] = graph[0][0];
	    pq.push({graph[0][0], {0, 0}});
	    
	    while (!pq.empty())
	    {
	        int currentCost = pq.top().first;
	        pair<int, int> currentPos = pq.top().second;
	        
	        pq.pop();
	        
	        if (d[currentPos.first][currentPos.second] < currentCost) continue;
	        
	        // 연결된 노드 검사
	        for (int i = 0; i < 4; i++)
	        {
	            int nx = currentPos.first + dx[i];
	            int ny = currentPos.second + dy[i];
	            
	            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
	            
	            int newCost = currentCost + graph[nx][ny];
	            if (newCost < d[nx][ny])
	            {
	                d[nx][ny] = newCost;
	                pq.push({newCost, {nx, ny}});
	            }
	        }
	    }
	    
	    cout << d[N-1][N-1] << '\n';
	}
}
