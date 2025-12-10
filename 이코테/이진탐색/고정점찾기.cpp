#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> arr;

int binarySearch(int startIdx, int endIdx)
{
    while (startIdx <= endIdx)
    {
        int midIdx = (startIdx + endIdx) / 2;
        if (midIdx == arr[midIdx]) return midIdx;
        else if (midIdx > arr[midIdx]) startIdx = midIdx + 1;
        else if (midIdx < arr[midIdx]) endIdx = midIdx - 1;
    }
    
    return -1;
}

int main(void)
{
    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    
    cout << binarySearch(0, N-1);
}
