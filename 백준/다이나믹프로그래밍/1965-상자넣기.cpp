#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;
int d[1001];

int main() {
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        arr.push_back(s);
    }
    
    fill_n(d, n, 1);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                d[i] = max(d[i], d[j]+1);
            }
        }
    }
    
    int max_count = 0;
    for (int i = 0; i < n; i++)
    {
        max_count = max(max_count, d[i]);
    }
    
    cout << max_count;
}
