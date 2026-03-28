#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int, int>> arr;

bool compare(const pair<int, int>& p1, const pair<int, int>& p2)
{
    if (p1.second == p2.second) return p1.first < p2.first;
    else return p1.second < p2.second;
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
    
    for (int i = 0; i < N; i++)
    {
        cout << arr[i].first << ' ' << arr[i].second << '\n';
    }
}
