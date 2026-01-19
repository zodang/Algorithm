#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> house;


int main(void)
{
    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        int p;
        cin >> p;
        
        house.push_back(p);
    }
    
    sort(house.begin(), house.end());
    
    int min_idx = (N - 1) / 2 ;
    cout << house[min_idx];
}
