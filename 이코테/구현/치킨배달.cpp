#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;

int N, M;

vector<pair<int, int>> house;
vector<pair<int, int>> chicken;

int get_chicken_distance(vector<pair<int, int>>& selected_chicken)
{
    int chicken_distance = 0;
    
    for (int i = 0; i < house.size(); i++)
    {
        int min_distance = INF;
        
        for (int j = 0; j < selected_chicken.size(); j++)
        {
            int d = abs(selected_chicken[j].first - house[i].first) + abs(selected_chicken[j].second - house[i].second);
            min_distance = min(min_distance, d);
        }
        
        chicken_distance += min_distance;
    }
    
    return chicken_distance;
}

int main()
{
    int answer = INF;
    
    cin >> N >> M;
    
    // 1. 집과 치킨집 위치 초기화
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int x;
            cin >> x;
            
            if (x == 1) house.push_back({i, j});
            else if (x == 2) chicken.push_back({i, j});
        }
    }
    
    // 2. M개의 치킨집 조합 구하기
    int n = chicken.size();
    
    vector<int> subArr(n, 0);
    for (int i = M; i < n; i++) subArr[i] = 1;
    
    do
    {
        vector<pair<int, int>> selected_chicken;
        
        for (int i = 0; i < n; i++)
        {
            if (subArr[i] == 0) selected_chicken.push_back(chicken[i]);
        }
        
        // 3. 모든 집과 M개의 치킨집으로부터의 최소 거리 구하기
        int city_chicken_distance = get_chicken_distance(selected_chicken);
        answer = min(answer, city_chicken_distance);
    }
    while (next_permutation(subArr.begin(), subArr.end()));
    
    cout << answer;
}
