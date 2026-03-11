#include <bits/stdc++.h>
using namespace std;

int N, R, C;

long long Z(int n, int r, int c)
{
    if (r == 0 && c == 0) return 0;
    else if (r == 0 && c == 1) return 1;
    else if (r == 1 && c == 0) return 2;
    else if (r == 1 && c == 1) return 3;
    
    int half = pow(2, n-1);
    int diff = pow(2, 2 * (n-1));
    
    if (r < half && c < half) return Z(n-1, r, c);
    else if (r < half && c >= half) return Z(n-1, r, c - half) + diff * 1;
    else if (r >= half && c < half) return Z(n-1, r - half, c) + diff * 2;
    else if (r >= half && c >= half) return Z(n-1, r - half, c - half) + diff * 3;
}

int main(void) {
    cin >> N >> R >> C;
    cout << Z(N, R, C);
}
