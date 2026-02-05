#include <bits/stdc++.h>
using namespace std;

int N, C;
vector<int> arr;

bool get_wifi_count(int interval)
{
    int count = 1;
    int lastIdx = 0;
    
    // 2. 중간거리 이상을 만족하는 곳마다 설치
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] - arr[lastIdx] >= interval)
        {
            count += 1;
            lastIdx = i;
        }
    }
    
    return count >= C;
}

int binary_search(int min_interval, int max_interval)
{
    if (min_interval > max_interval) return max_interval;
    
    // 1. 시작점+1과 끝지점의 중간 거리 구하기
    int mid_interval = (min_interval + max_interval) / 2;
    
    // 3. 설치 개수가 n개를 넘으면 중간지점 ~ 끝지점의 중간거리
    if (get_wifi_count(mid_interval)) return binary_search(mid_interval + 1, max_interval);
    
    // 4. 설치 개수가 n개를 못넘으면 시작점 + 1 ~ 중간지점까지의 중간거리
    else return binary_search(min_interval, mid_interval-1);
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
    
    cout << binary_search(1, arr[N-1] - arr[0]);
}
