#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int N, M;
int graph[501][501];


int main() {
    cin >> N >> M;
    
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            graph[i][j] = INF;
        }
    }
    
    for (int i = 1; i <= N; i++)
    {
        graph[i][i] = 0;
    }
    
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
    }
    
    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
    
    vector<int> arr(N+1, 0);
    
    for (int n = 1; n <= N; n++)
    {
        for (int i = 1; i <= N; i++)
        {
            if (i == n) continue;
            if (graph[n][i] < INF || graph[i][n] < INF) arr[n] += 1;
        }
    }
	
	int result = 0;
	for (int i = 1; i <= N; i++)
	{
	    if (arr[i] >= N-1) result++;
	}
    
    cout << result;
}
