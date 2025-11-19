#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int N, M, K, X;
vector<int> graph[300001];
int d[300001];

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    d[start] = 0;
    
    while(!q.empty())
    {
        int currentN = q.front();
        q.pop();
        
        for (int i = 0; i < graph[currentN].size(); i++)
        {
            if (d[graph[currentN][i]] == INF)
            {
                d[graph[currentN][i]] = d[currentN] + 1;
                q.push(graph[currentN][i]);
            }
        }
    }
}

int main() {
    
    // start부터 n번 노드까지의 최소거리 초기화
    fill_n(d, 300001, INF);
    
	cin >> N >> M >> K >> X;
	
	for (int i = 0; i < M; i++)
	{
	    int a, b;
	    cin >> a >> b;
	    graph[a].push_back(b);
	}
	
	bfs(X);
	
	int totalCount = 0;
	for (int i = 1; i <= N; i++)
	{
	    if (d[i] == K) 
	    {
	        totalCount++;
	        cout << i << '\n';
	    }
	}
	
	if (totalCount == 0) cout << -1;
}
