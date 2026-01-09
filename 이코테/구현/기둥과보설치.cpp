#include <bits/stdc++.h>
using namespace std;

bool pillar[101][101];
bool beam[101][101];

bool can_install_pillar(int x, int y)
{
    // 조건에 따라 기둥 설치가능 여부 판단
    bool possible = false;
    
    if (y == 0) possible = true;
    else if ((x-1 >= 0 && beam[x-1][y]) || beam[x][y]) possible = true;
    else if (y-1 >= 0 && pillar[x][y-1]) possible = true;
    
    return possible;
}

bool can_install_beam(int x, int y, int n)
{
    // 조건에 따라 보 설치가능 여부 판단
    bool possible = false;
    
    if ((y-1 >= 0 && pillar[x][y-1]) || (x+1 <= n && y-1 >= 0 && pillar[x+1][y-1])) possible = true;
    else if ((x-1 >= 0 && beam[x-1][y]) && (x+1 <= n && beam[x+1][y])) possible = true;
    
    return possible;
}

bool can_remove(int n)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            // 변경된 환경에서도 다른 구조물 설치가 가능한지 확인 
            if (pillar[i][j] && !can_install_pillar(i, j)) return false;
            if (beam[i][j] && !can_install_beam(i, j, n)) return false;
        }
    }
    
    return true;
}


vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            pillar[i][j] = 0;
            beam[i][j] = 0;
        }
    }
    
    for (int i  = 0; i < build_frame.size(); i++)
    {
        int xPos = build_frame[i][0];
        int yPos = build_frame[i][1];
        int type = build_frame[i][2];
        int install_type = build_frame[i][3];
        
        if (type == 0)
        {
            if (install_type == 0)
            {
                // 기둥 삭제
                pillar[xPos][yPos] = 0;
                if (!can_remove(n)) pillar[xPos][yPos] = 1;
            }
            else
            {
                // 기둥 설치
                if (can_pillar(xPos, yPos)) pillar[xPos][yPos] = 1;
            }
        }
        else
        {
            if (install_type == 0)
            {
                // 보 삭제
                beam[xPos][yPos] = 0;
                if (!can_remove(n)) beam[xPos][yPos] = 1;
            }
            else
            {
                // 보 설치
                if (can_beam(xPos, yPos, n)) beam[xPos][yPos] = 1;
            }
        }
    }
    
    for (int x = 0; x <= n; x++)
    {
        for (int y = 0; y <= n; y++)
        {
            // 구조물이 있는 위치 정답에 포함
            if (pillar[x][y]) answer.push_back({x, y, 0});
            if (beam[x][y]) answer.push_back({x, y, 1});
        }
    }
    
    return answer;
}
