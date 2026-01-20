#include <bits/stdc++.h>
using namespace std;

bool compare(pair<float, int> a, pair<float, int> b)
{
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    int reach_count[501];
    int fail_count[501];
    fill_n(reach_count, 501, 0);
    fill_n(fail_count, 501, 0);
    
    // 1. 도달한 플레이어 수와 클리어 못한 플레이어 수 구하기
    for (int i = 0; i < stages.size(); i++)
    {
        int current = stages[i];
        
        fail_count[current] += 1;
        
        for (int j = 1; j <= current; j++)
        {
            reach_count[j] += 1;
        }
    }
    
    // 2. 실패율 계산해서 answer에 추가
    vector<pair<float, int>> failrates;
    for (int i = 1; i <= N; i++)
    {
        int stage_idx = i;
        float failrate = 0;
        
        if (reach_count[i] != 0) failrate = (float)fail_count[i] / reach_count[i];
        failrates.push_back({failrate, stage_idx});
    }
    
    sort(failrates.begin(), failrates.end(), compare);
    
    for (int i = 0; i < N; i++)
    {
        answer.push_back(failrates[i].second);
    }
    
    return answer;
}
