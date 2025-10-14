#include <bits/stdc++.h>
using namespace std;

int v, e;
int graph[501][501];

const int INF = 1e9;

int main(void)
{
    cin >> v >> e;

    // 그래프 초기화
    for (int i = 0; i < 501; i++)
    {
        fill(graph[i], graph[i] + 501, INF);
    }

    // 자기 자신으로 가는 비용 초기화
    for (int a = 1; a <= v; a++)
    {
        for (int b = 1; b <= v; b++)
        {
            if (a == b) graph[a][b] = 0;
        }
    }

    // 간선 정보 초기화
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
    }

		// 플로이드 워셜 알고리즘 수행
    for (int i = 1; i <= v; i++)
    {
        for (int a = 1; a <= v; a++)
        {
            for (int b = 1; b <= v; b++)
            {
                graph[a][b] = min(graph[a][b], graph[a][i] + graph[i][b]);
            }
        }
    }
    
    // 그래프 결과 출력
    for (int a = 1; a <= v; a++)
    {
        for (int b = 1; b <= v; b++)
        {
            if (graph[a][b] == INF)
            {
                cout << "INFINTE" << ' ';
            }
            else
            {
                cout << graph[a][b] << ' ';
            }
        }
        
        cout << '\n';
    }
}
