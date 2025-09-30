#include <bits/stdc++.h>

using namespace std;

int X;
int d[30001];

int main(void)
{
    cin >> X;

    d[1] = 0;

    for (int i = 2; i <= X; i++)
    {
        // 가장 작은 d[i]값으로 업데이트
        d[i] = d[i - 1] + 1;
        if (i % 2 == 0) d[i] = min(d[i], d[i / 2] + 1);
        if (i % 3 == 0) d[i] = min(d[i], d[i / 3] + 1);
        if (i % 5 == 0) d[i] = min(d[i], d[i / 5] + 1);
    }

    cout << d[X];
}
