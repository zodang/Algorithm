#include <bits/stdc++.h>
using namespace std;

int N, K, L;

// 북, 서, 남, 동
int dx[4] = {0, 1, 0, -1}; 
int dy[4] = {1, 0, -1, 0};

int main() {
    
    // 보드 초기화
    cin >> N;
    vector<vector<int>> board(N + 1, vector<int>(N + 1, 0));
    
    // 뱀 위치 초기화
    int x = 1;
    int y = 1;
    int d = 0;
    
    // 뱀 위치 관리 큐
    queue<pair<int, int>> q;
    
    board[x][y] = 1;
    q.push(make_pair(x, y));
    
    // 사과 위치 초기화
    cin >> K;
    
    for (int i = 1; i <= K; i++)
    {
        int appleX = 0; 
        int appleY = 0;
        cin >> appleX >> appleY;
        board[appleX][appleY] = 2;
    }
    
    // 뱀 방향 전환 정보 초기화
    cin >> L;
    vector<pair<int, char>> vec;
    
    for (int i = 0; i < L; i++)
    {
        int sec = 0;
        char dir;
        cin >> sec >> dir;
        vec.push_back(make_pair(sec, dir));
    }
    
    // 시뮬레이션 구현
    int totalSecond = 0;
    int directionIndex = 0;
    
    while (true)
    {
        totalSecond++;
        
        // 이동 가능 여부 확인
        int nx = x + dx[d];
        int ny = y + dy[d];
        
        // 자기 자신과 닿거나 벽에 부딪힌 경우
        if ( nx < 1 || nx > N || ny < 1 || ny > N || board[nx][ny] == 1) break;
        
        // 사과를 만나지 못한 경우 꼬리 제거
        if (board[nx][ny] != 2)
        {
            pair<int, int> tailPos = q.front();
            board[tailPos.first][tailPos.second] = 0;
            q.pop();
        }
        
        // 머리 이동
        x = nx;
        y = ny;
        board[x][y] = 1;
        q.push(make_pair(x, y));
        
        // 방향 전환
        if (directionIndex < vec.size() && totalSecond == vec[directionIndex].first)
        {
            if (vec[directionIndex].second == 'D') d = (d + 1) % 4;
            else if (vec[directionIndex].second == 'L') d = (d + 3) % 4;
            
            directionIndex++;
        }
    }
    
    cout << totalSecond;
}
