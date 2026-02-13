#include <bits/stdc++.h>
using namespace std;

int T;
int dp[11];

int dp_result(int num)
{
    if (num == 1) return 1;
    if (num == 2) return 2;
    if (num == 3) return 4;
    
    return dp[num] = dp_result(num-1)+ dp_result(num-2) + dp_result(num-3);
}

int main() {
    cin >> T;
    
    for (int i = 0; i < T; i++)
    {
        int n;
        cin >> n;
        cout << dp_result(n) << '\n';
    }
}
