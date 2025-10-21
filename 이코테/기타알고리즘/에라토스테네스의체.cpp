#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int x;
    cin >> x;
    
    // 모든 수를 true로 초기화
    vector<int> arr(x + 1, true);
    
    for (int i = 2; i <= sqrt(x); i++)
    {
        if (arr[i] == false) continue;
        
        // i를 제외한 i의 배수 지우기
        int j = 2;
        while(i * j <= x)
        {
            arr[i * j] = false;
            j++;
        }
    }
    
    // 2부터 X까지의 모든 소수 출력
    for (int i = 2; i <= x; i++)
    {
        if (arr[i]) cout << i << ' ';
    }
}
