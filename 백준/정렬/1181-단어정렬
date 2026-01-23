#include <bits/stdc++.h>
using namespace std;

int N;
vector<string> arr;

bool compare(const string& a, const string& b)
{
    if (a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

int main(void)
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        arr.push_back(s);
    }
    
    sort(arr.begin(), arr.end(), compare);
    
    int idx = 1;
    while (idx < arr.size())
    {
        if (arr[idx] != arr[idx-1]) idx++;
        else arr.erase(arr.begin() + idx);
        
    }
    
    for (int i = 0; i < arr.size(); i++) cout << arr[i] << '\n';
}
