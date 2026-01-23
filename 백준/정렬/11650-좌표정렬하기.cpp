#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int N; 
vector<pair<int, int>> arr;

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
