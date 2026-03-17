#include <bits/stdc++.h>

using namespace std;

int M, N, H;

struct Pos
{
  int x;
  int y;
  int z;
};

vector<vector<vector<int>>> arr;
vector<Pos> start_pos;
Pos d[6] = {{-1, 0, 0}, {1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};


int main() {

    cin >> M >> N >> H;
    vector<vector<vector<int>>> arr(N, vector<vector<int>>(M, vector<int>(H, 0)));

    for (int h = 0; h < H; h++)
    {
        for (int n = 0; n < N; n++)
        {
            for (int m = 0; m < M; m++)
            {
                int t;
                cin >> t;
                arr[n][m][h] = t;
                
                if (t == 1) start_pos.push_back({n, m, h});
            }
        }
    }
    
    queue<Pos> q;
    
    for (int i = 0; i < start_pos.size(); i++)
    {
        q.push(start_pos[i]);
    }
    
    while (!q.empty())
    {
        Pos current = q.front();
        q.pop();
        
        for (int i = 0; i < 6; i++)
        {
            int nx = current.x + d[i].x;
            int ny = current.y + d[i].y;
            int nz = current.z + d[i].z;
            
            if (nx >= N || nx < 0 || ny >= M || ny < 0 || nz >= H || nz < 0) continue;
            
            if (arr[nx][ny][nz] == 0)
            {
                arr[nx][ny][nz] = arr[current.x][current.y][current.z] + 1;
                q.push({nx, ny, nz});
            }
        }
    }
    
    int max_day = 0;
    for (int h = 0; h < H; h++)
    {
        for (int n = 0; n < N; n++)
        {
            for (int m = 0; m < M; m++)
            {
                if (arr[n][m][h] == 0) 
                {
                    cout << -1;
                    return 0;
                }
                
                max_day = max(max_day, arr[n][m][h]);
            }
        }
    }

    cout << max_day - 1;
}
