#include <bits/stdc++.h>
using namespace std;

int N, M;
int x, y;
int d = 0;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void turn()
{
    // 반시계 방향으로 변경
    d--;
    if (d < 0) d = 3;
}

int main(void)
{
    cin >> N >> M;
    cin >> x >> y >> d;
    
    vector<vector<int>> map(N, vector<int>(M, 0));
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int x;
            cin >> x;
            map[i][j] = x;
        }
    }
    
    // 첫 배치 방문 처리
    map[x][y] = 1;
    int count = 1;
    
    int turnCount = 0;
    
    // 시뮬레이션 구현
    while (true)
    {
        if (turnCount == 4)
        {
            // 뒤로 이동
            int checkingX = x - dx[d];
            int checkingY = y - dy[d];
        
            // 뒤로 갈 수 없는 경우
            if (map[checkingX][checkingY] == 1 
            || checkingX < 0 || checkingX >= N || checkingY < 0 || checkingY >= M) break;
            
            // 뒤로 갈 수 있는 경우
            else
            {
                x = checkingX;
                y = checkingY;
            
                turnCount = 0;
            }
        }
        
        // 회전 후 왼쪽 이동
        turn();
        
        int checkingX = x + dx[d];
        int checkingY = y + dy[d];
        
        // 왼쪽으로 갈 수 있는 경우
        if (map[checkingX][checkingY] == 0 
        && checkingX >= 0 && checkingX < N && checkingY >= 0 && checkingY < M)
        {
            x = checkingX;
            y = checkingY;
            
            // 방문 처리
            map[x][y] = 1;
            count++;
            
            turnCount = 0;
        }
        
        // 왼쪽으로 갈 수 없는 경우
        else turnCount++;
    }
    
    cout << count;
    
}
