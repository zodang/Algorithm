#include <bits/stdc++.h>
using namespace std;

int N, K;
int S, X, Y;

int graph[201][201];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

// 바이러스 구조체 정의
struct Virus
{
    int type;
    int time;
    int x;
    int y;
};

// 바이러스 낮은 타입부터 오름차순 정렬
bool compareType(const Virus& a, const Virus& b)
{
    return a.type < b.type;
}

int main(void)
{
    cin >> N >> K;
    
    vector<Virus> virusArr;
    
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> graph[i][j];
            
            // 바이러스 시작점 추가
            if (graph[i][j] != 0)
            {
                Virus v;
                v.type = graph[i][j];
                v.time = 0;
                v.x = i;
                v.y = j;
                
                virusArr.push_back(v);
            }
        }
    }
    
    cin >> S >> X >> Y;
    
    // 바이러스 타입별 오름차순 정렬
    sort(virusArr.begin(), virusArr.end(), compareType);
    
    // 다중 시작점 BFS
    queue<Virus> q;
    for (int i = 0; i < virusArr.size(); i++)
    {
        q.push(virusArr[i]);
    }
    
    while (!q.empty())
    {
        Virus currentV = q.front();
        q.pop();
        
        // S초 도달 시 확산 종료
        if (currentV.time == S) continue;
        
        for (int i = 0; i < 4; i++)
        {
            int nx = currentV.x + dx[i];
            int ny = currentV.y + dy[i];
            
            if (nx <= 0 || nx > N || ny <= 0 || ny > N) continue;
            if (graph[nx][ny] != 0) continue;
            
            // 번식 이동
            graph[nx][ny] = currentV.type;
            
            // 새 바이러스 추가
            Virus v;
            v.type = currentV.type;
            v.time = currentV.time + 1;
            v.x = nx;
            v.y = ny;
            
            q.push(v);
        }
    }
    
    cout << graph[X][Y];
}
