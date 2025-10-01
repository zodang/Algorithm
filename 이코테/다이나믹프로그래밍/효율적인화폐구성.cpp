#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> arr;
vector<int> d(10001);

int main(void)
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    
    for (int i = 1; i <= M; i++)
    {
        // dp 값 초기화 (최소값을 찾아야 하므로 최대값으로 초기화)
        d[i] = 10001;
        
        for (int j = N - 1; j >= 0; j--)
        {
            // 입력한 화폐 단위인 경우 dp 값은 1
            if (i - arr[j] == 0) 
            {
                d[i] = 1;
                continue;
            }
            
            // 점화식 구현
            if (i - arr[j] > 0)
            {
                d[i] = min(d[i], 1 + d[i - arr[j]]);
            }
        }
    }
    
    if (d[M] >= 10001) cout << -1;
    else cout << d[M];
}
