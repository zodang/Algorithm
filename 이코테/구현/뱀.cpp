#include <bits/stdc++.h>
using namespace std;

int N, K, L;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int return_direction(char d, int currentD)
{
    if (d == 'L') currentD -= 1;
    else if (d == 'D') currentD += 1;
    
    if (currentD >= 4) return 0;
    if (currentD < 0) return 3;
    return currentD;
}

void debug_board(vector<vector<int>>& board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board.size(); j++)
        {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int main() {
	cin >> N;
	cin >> K;
	
	// 1. 보드 초기화 (0: 빈 칸, 1: 뱀칸, 2: 사과칸)
    vector<vector<int>> board(N+1, vector<int>(N+1, 0));
	
	// 2. 사과 위치 초기화
    for (int i = 0; i < K; i++)
    {
        int y, x;
        cin >> y >> x;
        board[y][x] = 2;
    }
    
    // 3. 회전 정보 초기화
    cin >> L;
    vector<pair<int, char>> dirInfo;
    
    for (int i = 0; i < L; i++)
    {
        int second;
        char dir;
        cin >> second >> dir;
        
        dirInfo.push_back({second, dir});
    }
    
    // 4. 시뮬레이션 정보 초기화
    int total_count = 0;
    int dirIdx = 0;
    
    int cx = 1;
    int cy = 1;
    int cd = 0;
    
    queue<pair<int, int>> snakePos;
    
    board[cx][cy] = 1;
    snakePos.push({cx, cy});

    while (true)
    {
        total_count++;
        
        // 5. 예상 머리 위치
        int ny = cy + dy[cd];
        int nx = cx + dx[cd];
        
        // 6. 충돌 체크 및 게임 종료
        if (nx <= 0 || nx > N || ny <= 0 || ny > N || board[ny][nx] == 1) 
        {
            cout << total_count;
            return total_count;
        }
        
        // 7. 사과 체크 및 꼬리 이동
        if (board[ny][nx] == 2)
        {
            snakePos.push({ny, nx});
            board[ny][nx] = 1;
        }
        else
        {
            snakePos.push({ny, nx});
            board[ny][nx] = 1;
            
            int ty = snakePos.front().first;
            int tx = snakePos.front().second;
            board[ty][tx] = 0;
            
            snakePos.pop();
        }
        
        // 8. 방향 전환
        if (dirIdx < dirInfo.size() && total_count == dirInfo[dirIdx].first)
        {
            cd = return_direction(dirInfo[dirIdx].second, cd);
            dirIdx++;
        }
        
        // 9. 머리 이동
        cy = ny;
        cx = nx;
        
    }
    
    cout << total_count;
}
