#include <bits/stdc++.h>
using namespace std;

int const INF = 1e9;

int N, M;
int X, K;
int graph[101][101];

int main(void)
{
    // 전체 회사 개수, 경로의 개수 초기화
    cin >> N >> M;
    
    // 그래프 초기화
    for (int i = 0; i < 101; i++)
    {
        // graph[i] : graph[i]의 주소
        fill(graph[i], graph[i] + 101, INF);
    }
    
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    
    // 판매 회사, 소개팅 상대 회사
    cin >> X >> K;
    
    // 자기 자신으로 가는 비용 초기화
    for (int i = 1; i <= N; i++)
    {
        graph[i][i] = 0;
    }

    // 플로이드 워셜 수행
    for (int i = 1; i <= N; i++)
    {
        for (int a = 1; a <= N; a++)
        {
            for (int b = 1; b <= N; b++)
            {
                if (graph[a][i] + graph[i][b] < graph[a][b])
                {
                    graph[a][b] = graph[a][i] + graph[i][b];
                }
            }
        }
    }
    
    int cost = graph[1][K] + graph[K][X];
    
    if (cost >= INF) cout << -1;
    else cout << cost;
}
