#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    // 작업 완료까지 걸리는 날짜
    queue<int> rest_days;
    int total_count = progresses.size();
    
    for (int i = 0; i < total_count; i++)
    {
        int x = (100 - progresses[i]) / speeds[i];
        if ((100 - progresses[i]) % speeds[i] > 0) x += 1;
        rest_days.push(x);
    }
    
    int release_day = rest_days.front(); 
    int feature = 0;

    // 배포일까지 가능한 기능 개수 카운트
    while (!rest_days.empty())
    {
        int current_day = rest_days.front();
        rest_days.pop();
        
        if (current_day > release_day)
        {
            release_day = current_day;
            answer.push_back(feature);
            feature = 0;
        }
        
        feature += 1;
    }
    
    answer.push_back(feature);
    return answer;
}
