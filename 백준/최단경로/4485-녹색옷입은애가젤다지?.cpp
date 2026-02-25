#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int arr[126][126];
int dp[126][126];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int GetMinCost(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            dp[i][j] = INF;
        }
    }
    
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    
    dp[0][0] = arr[0][0];
    pq.push({arr[0][0], {0, 0}});
    
    while (!pq.empty())
    {
        pair<int, pair<int, int>> top_node = pq.top();
        
        int cost = top_node.first;
        int cx = top_node.second.first;
        int cy = top_node.second.second;
        
        pq.pop();
        
        if (dp[cx][cy] < cost) continue;
        
        for (int d = 0; d < 4; d++)
        {
            // 연결된 노드 확인
            int nx = cx + dx[d];
            int ny = cy + dy[d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            
            if (dp[nx][ny] > dp[cx][cy] + arr[nx][ny])
            {
                dp[nx][ny] = dp[cx][cy] + arr[nx][ny];
                pq.push({dp[nx][ny], {nx, ny}});
            }
        }
    }
    
    return dp[n-1][n-1];
}

int main() {
	
	int test_count = 0;
	
	while(true)
	{
	    int N = 0;
	    cin >> N;
	    if (N == 0) break;
	    
	    test_count += 1;
	    
	    int min_cost = GetMinCost(N);
	    cout << "Problem " << test_count << ": " << min_cost << '\n';
	}
}
