#include <bits/stdc++.h>
using namespace std;

int N;
int d[101];
vector<pair<int, int>> arr;

bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
    return a.first < b.first;
}

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        arr.push_back({a, b});
    }
    
    sort(arr.begin(), arr.end(), compare);
    
    for (int i = 0; i < N; i++) d[i] = 1;
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j].first < arr[i].first && arr[j].second < arr[i].second)
            {
                d[i] = max(d[i], d[j]+1);
            }
        }
    }
    
    int max_count = 0;
    for (int i= 0; i < N; i++)
    {
        max_count = max(max_count, d[i]);
    }
    
    cout << N - max_count;
}
