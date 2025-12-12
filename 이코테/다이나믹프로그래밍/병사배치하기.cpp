#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> arr;

int main() {
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
	    int atk;
	    cin >> atk;
	    arr.push_back(atk);
	}
	
	vector<int> dpArr(N, 1);
	
	// 감소하는 부분의 최대 길이 갱신
	for (int i = 0 ; i < N; i++)
	{
	    for (int j = 0; j < i; j++)
	    {
	        if (arr[j] > arr[i]) dpArr[i] = max(dpArr[i], dpArr[j] + 1);
	    }
	}
	
	int max_count = 0;
	
	for (int i = 0; i < N; i++)
	{
	    max_count = max(max_count, dpArr[i]);
	}
	
	cout << N - max_count;
}
