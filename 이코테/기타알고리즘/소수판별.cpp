#include <bits/stdc++.h>
using namespace std;

bool IsPrimeNumber(int x)
{
    // 2부터 제곱근까지 검사
    for (int i = 2; i <= sqrt(x); i++)
    {
        int remain = x % i;
        if (remain == 0) return false;
    }
    
    return true;
}

int main(void)
{
    int x;
    cin >> x;
    
    if (IsPrimeNumber(x) == 0) cout << "합성수";
    else cout << "소수";
}
