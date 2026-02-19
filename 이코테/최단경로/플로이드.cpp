#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int n, m;
int arr[101][101];

int main() {
    
    cin >> n;
    cin >> m;
    
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < n+1; j++)
        {
            arr[i][j] = INF;
        }
    }
    
    for (int i = 0; i < n+1; i++)
    {
        arr[i][i] = 0;
    }
    
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        
        arr[a][b] = min(arr[a][b], c);
    }
    
    for (int k = 1; k < n+1; k++)
    {
        for (int i = 1; i < n+1; i++)
        {
            for (int j = 1; j < n+1; j++)
            {
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }
    
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            if (arr[i][j] >= INF) cout << 0 << ' ';
            else cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}
