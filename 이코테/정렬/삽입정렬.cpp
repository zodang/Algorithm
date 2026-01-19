#include <bits/stdc++.h>
using namespace std;

int arr[10] = {2,4,5,1,3,6,8,9,7,0};

int main() {
	for (int i = 1; i < 10; i++)
	{
	    for (int j = i; j > 0; j--)
	    {
	        // i부터 내려오면서 순서가 올바르지 않다면 swap, 올바르면 break
	        if (arr[j-1] >= arr[j]) swap(arr[j-1], arr[j]);
	        else break;
	    }
	}

    for (int i = 0; i < 10; i++) cout << arr[i] << ' ';
}
