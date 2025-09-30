#include <bits/stdc++.h>

using namespace std;

int N;
vector <int> fArr;

int main() {
		// DP 테이블
    vector <int> d;
	
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        fArr.push_back(x);
    }

    d.push_back(fArr[0]);
    d.push_back(max(fArr[0], fArr[1]));

    for (int i = 2; i < N; i++)
    {
        int r = max(d[i - 2] + fArr[i], d[i - 1]);
        d.push_back(r);
    }

    cout << d[N - 1];
}
