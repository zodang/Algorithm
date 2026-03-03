#include <bits/stdc++.h>
using namespace std;

int N;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

char graph[7][7];
vector<pair<int, int>> blank_pos;
vector<pair<int, int>> teacher_pos;

bool FindStudent()
{
    for (int i = 0; i < teacher_pos.size(); i++)
    {
        for (int d = 0; d < 4; d++)
        {
            int cx = teacher_pos[i].first;
            int cy = teacher_pos[i].second;
            
            while (true)
            {
                cx += dx[d];
                cy += dy[d];
                
                if (cx > N || cx <= 0 || cy > N || cy <= 0) break;
                if (graph[cx][cy] == 'O') break;
                if (graph[cx][cy] == 'S') return true;
            }
        }
    }
    
    return false;
}

void PutObstacle(int start_idx, int count)
{
    if (count == 3)
    {
        // 감시 구현
        if (FindStudent() == false)
        {
            cout << "YES";
            exit(0);
        }
        return;
    }
    
    for (int i = start_idx; i < blank_pos.size(); i++)
    {
        int x = blank_pos[i].first;
        int y = blank_pos[i].second;
        
        graph[x][y] = 'O';
        PutObstacle(i+1, count+1);
        
        graph[x][y] = 'X';
    }
}

int main(void)
{
    cin >> N;
    
    for (int i = 1; i <= N; i++)
    {
       for (int j = 1; j <= N; j++)
       {
           cin >> graph[i][j];
           
           if (graph[i][j] == 'T') teacher_pos.push_back({i, j});
           if (graph[i][j] == 'X') blank_pos.push_back({i, j});
       }
    }
    
    PutObstacle(0, 0);
    cout << "NO";
}
