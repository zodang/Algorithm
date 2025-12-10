#include <bits/stdc++.h>
using namespace std;

int N, C;
vector<int> arr;

int binarySearch(int startD, int endD)
{
    // 인접한 두 공유기의 최대 거리
    int result = 0;
    
    while (startD <= endD)
    {
        // midD를 넘는 곳마다 공유기 설치
        int midD = (startD + endD) / 2;
        int count = 1;
        int wifiPos = arr[0];
        
        for (int i = 0; i < N; i++)
        {
            if (arr[i] - wifiPos >= midD)
            {
                wifiPos = arr[i];
                count++;
            }
        }
        
        // 공유기 개수 미달 → endD 줄여서 재탐색
        if (count < C) endD = midD - 1;
        
        // 공유기 개수 충족 → startD 늘려서 재탐색
        else
        {
            startD = midD + 1;
            result = midD;
        }
    }
    
    return result;
}

int main(void)
{
    cin >> N >> C;
    
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    
    sort(arr.begin(), arr.end());
    
    int minD = 1;
    int maxD = arr[N-1] - arr[0];
    
    cout << binarySearch(minD, maxD);
}
