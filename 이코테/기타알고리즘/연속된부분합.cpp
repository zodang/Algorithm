#include <bits/stdc++.h>
using namespace std;

int N, M = 0;
vector<int> arr;

int main(void) 
{
    cin >> N >> M;
    
    for (int i = 0; i < N; i++)
    {
        int a; 
        cin >> a;
        arr.push_back(a);
    }
    
    int a, b = 0;
    int count = 0;
    int sum = arr[0];
    
    for (a = 0; a < N; a++)
    {
        while (sum < M && b < N)
        {
            // 부분합이 M보다 작은 경우 arr[b]만큼 추가
            b += 1;
            sum += arr[b];
        }
        
        // 부분합이 M과 같은 경우 체크
        if (sum == M) count++;
        
        // 부분합이 M보다 큰 경우 arr[a]만큼 감소
        sum -= arr[a];
    }
    
    cout << count;
}
