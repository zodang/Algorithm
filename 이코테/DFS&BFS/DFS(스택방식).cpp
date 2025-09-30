# include <bits/stdc++.h>

using namespace std;

bool visited[9];
vector<int> graph[9];

void dfs(int start)
{
    stack<int> s;
    
    s.push(start);
     
    while (!s.empty())
    {
        int x = s.top();
        s.pop();
        
        if (visited[x]) continue;
        
        visited[x] = true;
        cout << x << ' ';
        
        for (int i = (int)graph[x].size() - 1; i >= 0; i--)
        {
            int y = graph[x][i];
            if (!visited[y])
            {
                s.push(y);
            }
        }
    }
}

int main(void)
{
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(8);
    
    graph[2].push_back(1);
    graph[2].push_back(7);
    
    graph[3].push_back(1);
    graph[3].push_back(4);
    graph[3].push_back(5);
    
    graph[4].push_back(3);
    graph[4].push_back(5);
    
    graph[5].push_back(3);
    graph[5].push_back(4);
    
    graph[6].push_back(7);
    
    graph[7].push_back(2);
    graph[7].push_back(6);
    graph[7].push_back(8);
    
    graph[8].push_back(1);
    graph[8].push_back(7);
    
    dfs(1);
}
