#include <bits/stdc++.h>
using namespace std;

int n;
int dp[1001];

int GetDp(int x)
{
    if (x == 1) return 1;
    if (x == 2) return 3;
    if (dp[x] != 0) return dp[x];
    
    return dp[x] = (GetDp(x-1) + GetDp(x-2) * 2) % 10007;
}

int main() {
    cin >> n;
    cout << GetDp(n);
}
