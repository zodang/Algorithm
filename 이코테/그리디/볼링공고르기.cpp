#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> vec;

int main() {
	cin >> N >> M;
	
	for (int i = 0; i < N; i++)
	{
        int x;
        cin >> x;
        vec.push_back(x);
	}
	
	int count = 0;
	
	for (int i = 0; i < N; i++)
	{
	    for (int j = i + 1; j < N; j++)
	    {
	        if (vec[i] != vec[j]) count++;
	    }
	}
	
	cout << count;
}
