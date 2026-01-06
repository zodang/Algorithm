#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> rotate(vector<vector<int>>& key, int m)
{
    vector<vector<int>> rotated_key(m, vector<int>(m, 0));
    
    // 오른쪽 회전
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            rotated_key[i][j] = key[j][(m-1)-i];
        }
    }

    return rotated_key;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    
    int M = key[0].size();
    int N = lock[0].size();
    int board_size = N + ((M - 1) * 2);
    
    // 1. Key가 움직일 수 있는 확장된 범위의 Lock
    vector<vector<int>> check_board(board_size, vector<int>(board_size, 0));
    
    // 2. 확장판 중앙에 Lock 초기화
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            check_board[i+M-1][j+M-1] = lock[i][j];
        }
    }
    
    int rotate_count = 0;
    while (rotate_count < 4)
    {
        // 3. 확장판 내 Key 이동
        for (int i = 0; i < check_board.size() - (M - 1); i++)
        {
            for (int j = 0; j < check_board.size() - (M - 1); j++)
            {
                // (i, j): Key의 좌상단
                for (int x = 0; x < M; x++)
                {
                    for (int y = 0; y < M; y++)
                    {
                        check_board[i+x][j+y] += key[x][y];
                    }
                }
                
                // 4. 확장판의 Lock 위치가 모두 맞물렸는지 확인
                bool isClear = true;
                for (int x = 0; x < N; x++)
                {
                    for (int y = 0; y < N; y++)
                    {
                        if (check_board[x + M - 1][y + M - 1] == 1) continue;
                        else  
                        {
                            isClear = false;
                            break;
                        }   
                    }
                }
        
                // 5. 맞물린다면 결과 return
                if (isClear) return true;
                
                // 6. 맞물리지 않다면 확장판 복구
                for (int x = 0; x < M; x++)
                {
                    for (int y = 0; y < M; y++)
                    {
                        check_board[i+x][j+y] -= key[x][y];
                    }
                }
            }
        }
        
        // 7. key 회전
        key = rotate(key, M);
        rotate_count++;
    }
    
    return answer;
}
