#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> dp;

int main() {
	cin >> n;
	
	dp.push_back(1);
	
	int u2 = 2, u3 = 3, u5 = 5;
	int i2 = 0, i3 = 0, i5 = 0;
    
    while (dp.size() < n)
    {
        u2 = dp[i2] * 2;
        u3 = dp[i3] * 3;
        u5 = dp[i5] * 5;
        
        int min_u = min({u2, u3, u5});
        
        if (min_u == u2) i2++;
        if (min_u == u3) i3++;
        if (min_u == u5) i5++;
        
        dp.push_back(min_u);
    }
	
    cout << dp[n-1];
}
