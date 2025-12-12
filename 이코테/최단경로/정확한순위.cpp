#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int N, M;
int graph[501][501];

int main() 
{
    cin >> N >> M;
    
    for (int i = 1; i <= N; i++)
    {
        fill_n(graph[i], N + 1, INF);
    }
    
    for (int i = 1; i <= M; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x][y] = 1;
    }
    
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i == j) graph[i][j] = 0;
        }
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

    int count = 0;
    
    for (int i = 1; i <= N; i++)
    {
        int comparableCount = 0;
        
        for (int j = 1; j <= N; j++)
        {
            if (graph[i][j] != INF || graph[j][i] != INF) comparableCount++;
        }
        
        if (comparableCount == N) count++;
    }
    
    cout << count;
}
