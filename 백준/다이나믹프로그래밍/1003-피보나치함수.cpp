#include <bits/stdc++.h>
using namespace std;

int T;
int dp_0[41];
int dp_1[41];

int Fibonacci_0(int n)
{
    if (n == 1) return 0;
    if (n == 0) return dp_0[n];
    if (dp_0[n] != 0) return dp_0[n];
    
    return dp_0[n] = Fibonacci_0(n-1)+ Fibonacci_0(n-2);
}

int Fibonacci_1(int n)
{
    if (n == 0) return 0;
    if (n == 1) return dp_1[n];
    if (dp_1[n] != 0) return dp_1[n];
    
    return dp_1[n] = Fibonacci_1(n-1)+ Fibonacci_1(n-2);
    
}

int main(void) {
    cin >> T;
    
    dp_0[0] = 1;
    dp_1[0] = 0;
    
    dp_0[1] = 0;
    dp_1[1] = 1;
    
    for (int t = 0; t < T; t++)
    {
        int n;
        cin >> n;
        
        cout << Fibonacci_0(n) << ' ' << Fibonacci_1(n) << '\n';
    }
}
