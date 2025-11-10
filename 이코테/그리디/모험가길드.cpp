#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> vec;

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        vec.push_back(x);
    }

    sort(vec.begin(), vec.end());
    
    int guildCount = 0;
    int currentSum = 0;
    
    for (int i = 0; i < N; i++)
    {
        currentSum++;
        
        // 최소 길드원 확보
        if (currentSum >= vec[i])
        {
            guildCount++;
            currentSum = 0;
        }
    }
    
    cout << guildCount;
}
