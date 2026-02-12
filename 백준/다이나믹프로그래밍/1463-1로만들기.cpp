#include <bits/stdc++.h>
using namespace std;

int N;
int dp[1000001];

int main() {
	cin >> N;
	
	dp[1] = 0;
	
	for (int n = 2; n <= N; n++)
	{
	    int temp = dp[n-1] + 1;
	    
	    if (n % 3 == 0) temp = min(temp, dp[n / 3] + 1);
	    if (n % 2 == 0) temp = min(temp, dp[n / 2] + 1);
	    
	    dp[n] = temp;
	}
	
	cout << dp[N];
}
