#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    // 작업 완료까지 걸리는 날짜
    vector<int> rest_days;
    int total_count = progresses.size();
    
    for (int i = 0; i < total_count; i++)
    {
        int x = (100 - progresses[i]) / speeds[i];
        if ((100 - progresses[i]) % speeds[i] > 0) x += 1;
        rest_days.push_back(x);
    }
    
    int big = rest_days[0]; 
    int feature = 0;
    
    for (int i = 1; i < rest_days.size(); i++)
    {
        feature++;
        
        // 큰 날짜 도달 시 배포
        if (rest_days[i] > big)
        {
            answer.push_back(feature);
            big = rest_days[i];
            feature = 0;
            continue;
        }
    }

    answer.push_back(feature + 1);
    return answer;
}
