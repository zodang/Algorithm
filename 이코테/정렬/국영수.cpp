#include <bits/stdc++.h>
using namespace std;

struct Score
{
    string name;
    int korean;
    int english;
    int math;
};

bool compare(const Score& a, const Score& b)
{
    if (a.korean == b.korean && a.english == b.english && a.math == b.math) return a.name < b.name;
    if (a.korean == b.korean && a.english == b.english) return a.math > b.math;
    if (a.korean == b.korean) return a.english < b.english;
    return a.korean > b.korean;
}

int N;
vector<Score> scoreArr;

int main(void)
{
    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        Score score;
        cin >> score.name >> score.korean >> score.english >> score.math;
        
        scoreArr.push_back(score);
    }
    
    sort(scoreArr.begin(), scoreArr.end(), compare);
    
    for (int i = 0; i < N; i++)
    {
        cout << scoreArr[i].name << '\n';
    }
}
