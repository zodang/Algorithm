#include <bits/stdc++.h>
using namespace std;

int N;
int T[16] = {0};
int P[16] = {0};
int d[16] = {0};

int main() {
	cin >> N;
	
	for (int i = 1; i <= N; i++)
	{
	    int t, p;
	    cin >> t >> p;
	    T[i] = t;
	    P[i] = p;
	}
	
	int max_sum = 0;
	
	for (int i = N; i > 0; i--)
	{
	    // 1. 퇴사일 초과 여부 확인
	    if (i + T[i] > N+1)
	    {
	        d[i] = max_sum;
	        continue;
	    }
	    
	    // 2. 최대 이익과 비교
	    int next_time = i + T[i]; 
	    
	    if (d[next_time] + P[i] > max_sum)
	    {
	        d[i] = d[next_time] + P[i];
	        max_sum = d[i];
	    }
	    else d[i] = max_sum;
	}
	
	cout << max_sum;
}
