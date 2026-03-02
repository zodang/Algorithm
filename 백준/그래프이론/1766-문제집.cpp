#include <bits/stdc++.h>
using namespace std;

int N, M;
int indegree[32001];

int main() {
	cin >> N  >> M;
	
	vector<vector<int>> arr(N+1);
	
	for (int i = 0; i < M; i++)
	{
	    int a, b;
	    cin >> a >> b;
	    
	    arr[a].push_back(b);
	    indegree[b] += 1;
	}
	
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= N; i++)
	{
	    if (indegree[i] == 0)
	    pq.push(i);
	}
	
	vector<int> result;
	while (!pq.empty())
	{
	    int current_node = pq.top();
	    result.push_back(current_node);
	    
	    pq.pop();
	    
	    for (int i = 0; i < arr[current_node].size(); i++)
	    {
	        int linked_node = arr[current_node][i];
	        indegree[linked_node] -= 1;
	        
	        if (indegree[linked_node] == 0)
	        {
	            pq.push(linked_node);
	        }
	    }
	}
	
	for (int i = 0; i < result.size(); i++)
	{
	    cout << result[i] << ' ';
	}
}
