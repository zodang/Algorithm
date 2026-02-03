#include <bits/stdc++.h>
using namespace std;

int N, x;
vector<int> arr;

int lower_bound(int startIdx, int endIdx, int target)
{
    while (startIdx < endIdx)
    {
        int midIdx = (startIdx + endIdx) / 2;
        
        if (arr[midIdx] < target) startIdx = midIdx + 1;
        else endIdx = midIdx;
    }
    
    return startIdx;
}

int upper_bound(int startIdx, int endIdx, int target)
{
    while (startIdx < endIdx)
    {
        int midIdx = (startIdx + endIdx) / 2;
        
        if (arr[midIdx] <= target) startIdx = midIdx + 1;
        else endIdx = midIdx;
    }
    
    return startIdx;
}

int main() {
	cin >> N >> x;
	
	for (int i = 0; i < N; i++)
	{
	    int a;
	    cin >> a;
	    arr.push_back(a);
	}
	
	int leftIdx = lower_bound(0, N-1, x);
    int rightIdx = upper_bound(0, N-1, x);
    
    cout << leftIdx << ' ' << rightIdx;
}
