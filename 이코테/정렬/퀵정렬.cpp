#include <bits/stdc++.h>
using namespace std;

int arr[10] = {2,4,5,1,3,6,8,9,7,0};

void quick_sort(int startIdx, int endIdx)
{
    if (startIdx >= endIdx) return;
    
    int pivotIdx = startIdx;
    int leftIdx = startIdx + 1;
    int rightIdx = endIdx;
    
    while (leftIdx <= rightIdx)
    {
        while (leftIdx <= endIdx && arr[leftIdx] <= arr[pivotIdx]) leftIdx++;
        while (rightIdx > startIdx && arr[rightIdx] >= arr[pivotIdx]) rightIdx--;
        
        if (leftIdx <= rightIdx) swap(arr[leftIdx], arr[rightIdx]);
        else swap(arr[rightIdx], arr[pivotIdx]);
    }
    
    quick_sort(startIdx, rightIdx-1);
    quick_sort(rightIdx+1, endIdx);
}

int main() {
	
	quick_sort(0, 9);

    for (int i = 0; i < 10; i++) cout << arr[i] << ' ';
}
