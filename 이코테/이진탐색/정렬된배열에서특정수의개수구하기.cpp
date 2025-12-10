#include <bits/stdc++.h>
using namespace std;

int N, x;
vector<int> arr;

int main(void)
{
    cin >> N >> x;
    
    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        arr.push_back(t);
    }
    
    int lowerIdx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
    int upperIdx = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
    
    int count = upperIdx - lowerIdx;
    
    if (count == 0) cout << -1;
    else cout << count;
}
