#include <bits/stdc++.h>
using namespace std;

int N, M, K;
vector<int> vec;

int main() {

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        vec.push_back(x);
    }

    sort(vec.begin(), vec.end(), greater<int>());
    
    int sum = 0;
    
    for (int i = 1; i <= M; i++)
    {
        // K번 초과 여부 확인
        bool isExceed = i % (K+1) == 0;
        
        if (isExceed) sum += vec[1];
        else sum += vec[0]; 
    }
    
    cout << sum;
}
