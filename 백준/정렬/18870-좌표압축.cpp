#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> arr;
vector<int> sorted_arr;

int main() {
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
	    int x;
	    cin >> x;
	    arr.push_back(x);
	    sorted_arr.push_back(x);
	}
	
	sort(sorted_arr.begin(), sorted_arr.end());
	sorted_arr.erase(unique(sorted_arr.begin(), sorted_arr.end()), sorted_arr.end());
	
	for (int i = 0;  i < N; i++)
	{
	    int idx = lower_bound(sorted_arr.begin(), sorted_arr.end(), arr[i]) - sorted_arr.begin();
	    cout << idx << ' ';
	}
}
