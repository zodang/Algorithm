#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int, pair<int, string>>> info; // idx, age, name

bool CompareInfo(pair<int, pair<int, string>> a, pair<int, pair<int, string>> b)
{
    if (a.second.first == b.second.first) return a.first < b.first;
    return a.second.first < b.second.first;
}

int main() {
	cin >> N; 
	for (int i = 0; i < N; i++)
	{
	    int age;
	    string name;
	    cin >> age >> name;
	    
	    info.push_back({i, {age, name}}); 
	}
    
    sort(info.begin(), info.end(), CompareInfo);
    
    for (int i = 0; i < N; i++)
    {
        cout << info[i].second.first << ' ' << info[i].second.second << '\n';
    }
}
