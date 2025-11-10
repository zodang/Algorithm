#include <bits/stdc++.h>
using namespace std;

int N, M;

int main() {

    cin >> N >> M;

    // 2차원 벡터 초기화
    vector<vector<int>> vec(N, vector<int>(M, 10000));
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int x;
            cin >> x;
            vec[i][j] = x; 
        }
    }

    int maxValue = 0;

    for (int i = 0; i < N; i++)
    {
        // N행에서 가장 작은 수들 중에서 가장 큰 수 비교
        sort(vec[i].begin(), vec[i].end());
        if (maxValue <= vec[i][0]) maxValue = vec[i][0];
    }
    
    cout << maxValue;
}
