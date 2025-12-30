#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> arr;

int main(void) 
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    
    sort(arr.begin(), arr.end());
    
    int target = 1;
    
    for (int i = 0; i < arr.size(); i++)
    {
        if (target >= arr[i]) target += arr[i];
        else break;
    }
    
    cout << target;
}
