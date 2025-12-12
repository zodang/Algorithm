#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, m;
int graph[101][101];

int main() 
{
    cin >> n;
    cin >> m;
    
    for (int i = 1; i <= n; i++)
    {
        fill_n(graph[i], n + 1, INF);
    }
    
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = min(graph[a][b], c);
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j) graph[i][j] = 0;
        }
    }
    
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (graph[i][j] == INF) cout << 0 << ' ';
            else cout << graph[i][j] << ' ';
        }
        
        cout << '\n';
    }
}
