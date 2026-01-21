#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> arr;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
	cin >> N;
	for (int i = 0; i < N; i++)
	{
	    int x;
	    cin >> x;
	    
	    arr.push_back(x);
	}
	
	int min_abs = 2e9;
	
	int left_idx = 0;
	int right_idx = arr.size() - 1;
	
	int answer1 = 0;
	int answer2 = 0;
	
	// 1. 오름차순 정렬
	sort(arr.begin(), arr.end());
	
	while (left_idx < right_idx)
	{
	    int sum = arr[left_idx] + arr[right_idx];
	    
	    // 2. 용액의 합이 최소값인 경우
	    if (abs(sum) < min_abs)
	    {
	        min_abs = abs(sum);
	        answer1 = left_idx;
	        answer2 = right_idx;
	    }
	    
	    // 3. 용액의 합에 따라 범위 조정
	    if (sum > 0) right_idx--;
	    else left_idx++;
	}
	
	cout << arr[answer1] << ' ' << arr[answer2];
}
