#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> arr;

int binary_search(int leftIdx, int rightIdx)
{
    while (leftIdx <= rightIdx)
    {
        int midIdx = (leftIdx + rightIdx) / 2;
        
        if (midIdx == arr[midIdx]) return midIdx;
        
        if (midIdx > arr[midIdx]) leftIdx = midIdx + 1;
        else rightIdx = midIdx - 1;
    }
    
    return -1;
}


int main()
{
    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    
    cout << binary_search(0, N-1);
}
