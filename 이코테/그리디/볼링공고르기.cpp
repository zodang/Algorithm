#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[11];

int main() 
{
    cin >> N >> M;
    
    fill_n(arr, M + 1, 0);
    
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        arr[x] += 1;
    }
    
    int count = 0;
    int leftCount = N;
    
    for (int i = 1; i < M + 1; i++)
    {
        leftCount -= arr[i];
        count += arr[i] * leftCount;
    }
    
    cout << count;
}
