#include <bits/stdc++.h>
using namespace std;

int N;
int arr[1001][3];
int dp[1001][3];

int main() {
	cin >> N;
	
	for (int i = 1; i <= N; i++)
	{
	    cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}
	
	for (int i = 0; i < 3; i++)
	{
	    dp[1][i] = arr[1][i];
	}

    for (int i = 2; i <= N; i++)
    {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + arr[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + arr[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + arr[i][2];
    }
    
    int min_cost = min({dp[N][0], dp[N][1], dp[N][2]});
    cout << min_cost;
}
