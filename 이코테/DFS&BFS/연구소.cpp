#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> graph;

vector<pair<pair<int, int>, int>> info;
vector<pair<int, int>> virus_pos;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

vector<vector<int>> move_virus(const vector<vector<int>>& g)
{
    vector<vector<int>> virus_graph = g;
    queue<pair<int, int>> q;
    
    for (int i = 0; i < virus_pos.size(); i++)
    {
        q.push({virus_pos[i].first, virus_pos[i].second});
    }
    
    while (!q.empty())
    {
        for (int d = 0; d < 4; d++)
        {
            int nx = q.front().first + dx[d];
            int ny = q.front().second + dy[d];
            
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (virus_graph[nx][ny] != 0 ) continue;
            
            virus_graph[nx][ny] = 2;
            q.push({nx, ny});
        }
        
        q.pop();
    }
    
    return virus_graph;
}


int main() {
    int answer = 0;

    cin >> N >> M;
    
    graph.resize(N);
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int x;
            cin >> x;
            graph[i].push_back(x);
            
            info.push_back({{i, j}, x});
            if (x == 2) virus_pos.push_back({i, j});
        }
    }
    
    // 1. 새 벽 3개 위치 선택
    vector<int> subArr(N*M, 1);
    for (int i = 0; i < 3; i++) subArr[i] = 0;
    
    do 
    {
        vector<int> wallArr;
        vector<vector<int>> newGraph = graph;
        bool is_all_zero = true;
        
        for (int i = 0; i < N*M; i++)
        {
            if (subArr[i] == 0) wallArr.push_back(i);
        }
        
        // 2. 벽 세우기
        for (int i = 0; i < wallArr.size(); i++)
        {
            int idx = wallArr[i];
            
            int xPos = info[idx].first.first;
            int yPos = info[idx].first.second;
            
            if (graph[xPos][yPos] != 0)
            {
                is_all_zero = false;
                break;
            }
            
            newGraph[xPos][yPos] = 1;
        }
        
        if (!is_all_zero) continue;
        
        // 3. 바이러스 이동
        newGraph = move_virus(newGraph);
        
        // 4. 빈 칸 개수 갱신
        int count = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (newGraph[i][j] == 0) count++;
            }
        }

        answer = max(answer, count);
    }
    while (next_permutation(subArr.begin(), subArr.end()));
    
    cout << answer;
}
