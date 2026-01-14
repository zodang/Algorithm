#include <bits/stdc++.h>
using namespace std;

struct Virus
{
    int v_type;
    int x_pos;
    int y_pos;
};

bool compare(const Virus& a, const Virus& b)
{
    return a.v_type < b.v_type;
}

int N, K;
int S, X, Y;
int graph[201][201];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vector<Virus> virusArr;
queue<Virus> q;

void spread_virus()
{
    int v_size = q.size();
    
    for (int i = 0; i < v_size; i++)
    {
        Virus current_v = q.front();
        
        int ct = current_v.v_type;
        int cx = current_v.x_pos;
        int cy = current_v.y_pos;
        
        for (int d = 0; d < 4; d++)
        {
            int nx = cx + dx[d];
            int ny = cy + dy[d];
            
            if (nx <= 0 || nx > N || ny <= 0 || ny > N) continue;
            if (graph[nx][ny] != 0) continue;
            
            graph[nx][ny] = ct;
            q.push({ct, nx, ny});
        }
        
        q.pop();
    }
}

int main() {
	
	// 1. 데이터 초기화
	cin >> N >> K;
    
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j<= N; j++)
        {
            int t;
            cin >> t;
            graph[i][j] = t;
            
            if (t != 0) virusArr.push_back({t, i, j});
        }
    }
    
    cin >> S >> X >> Y;
    
    // 2. 바이러스 타입에 따라 오름차순 정렬
    sort(virusArr.begin(), virusArr.end(), compare);
    
    // 3. queue에 바이러스 추가
    for (int i = 0; i < virusArr.size(); i++)
    {
        q.push(virusArr[i]);
    }
    
    // 4. S초동안 전염
    int s = 0;
    while (s < S)
    {
        s += 1;
        spread_virus();
    }
    
    cout << graph[X][Y];
}
