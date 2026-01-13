#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int N, M, K, X;

vector<vector<int>> graph;
bool visited[300001];
int d[300001];

void bfs(int start)
{
    queue<int> q;
    
    q.push(start);
    visited[start] = true;
    d[start] = 0;
    
    while (!q.empty())
    {
        int currentIdx = q.front();
        
        q.pop();
        
        for (int i = 0; i < graph[currentIdx].size(); i++)
        {
            int nearIdx = graph[currentIdx][i];
            if (visited[nearIdx]) continue;
            
            q.push(nearIdx);
            visited[nearIdx] = true;
            d[nearIdx] = d[currentIdx] + 1;
        }
    }
}

int main() {
    
    // 1. 데이터 초기화
	cin >> N >> M >> K >> X;
	
	graph.resize(N+1);
	fill_n(visited, N+1, 0);
	fill_n(d, N+1, 0);
	
	for (int i = 0; i < M; i++)
	{
	    int a, b;
	    cin >> a >> b;
	    graph[a].push_back(b);
	}
	
	// 2. bfs 실행
	bfs(X);
	
	// 3. 최소거리가 K인 노드 출력력
	int count = 0; 
	
	for (int i = 1; i < N+1; i++)
	{
	    if (d[i] == K) 
	    {
	        count++;
	        cout << i << '\n';
	    }
	}

    if (count == 0) cout << -1 << '\n';
}

