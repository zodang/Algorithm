#include <bits/stdc++.h>
using namespace std;

struct Info
{
    string name;
    int korean;
    int english;
    int math;
};

int N;
vector<Info> infoArr;

bool compareInfo(const Info& a, const Info& b)
{
    if (a.korean == b.korean && a.english == b.english && a.math == b.math) return a.name < b.name;
    if (a.korean == b.korean && a.english == b.english) return a.math > b.math;
    if (a.korean == b.korean) return a.english < b.english;
    return a.korean > b.korean;
}

int main() {

    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        Info newInfo;
        cin >> newInfo.name >> newInfo.korean >> newInfo.english >> newInfo.math;
        infoArr.push_back(newInfo);
    }
    
    sort(infoArr.begin(), infoArr.end(), compareInfo);
    
    for (int i = 0; i < infoArr.size(); i++)
    {
        cout << infoArr[i].name << '\n';
    }
}
