#include <bits/stdc++.h>
using namespace std;

int N;
int d[2001];
vector<int> cp;

int main() {
	
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
	    int x;
	    cin >> x;
	    cp.push_back(x);
	}
	
	for (int i = 0; i < N; i++)
	{
	    d[i] = 1;
	    
	    for (int j = 0; j < i; j++)
	    {
	        if (cp[j] > cp[i])
	        {
	            d[i] = max(d[i], d[j] + 1);
	        }
	    }
	}
	
	int max_count = 0;
	for (int i = 0; i < N; i++)
	{
	    max_count = max(max_count, d[i]);
	}
	
	cout << N - max_count;
}
