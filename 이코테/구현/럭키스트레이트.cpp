#include <bits/stdc++.h>
using namespace std;

int N;

int main(void)
{
    cin >> N;
    
    // int to string
    string NString = to_string(N);
    
    int leftSum = 0;
    int rightSum = 0;
    
    int midIndex = NString.size() * 0.5f;
    
    for (int i = 0; i < NString.size(); i++)
    {
        int currentValue = NString[i] - '0'; 
        
        if (i < midIndex) leftSum += currentValue;
        else rightSum += currentValue;
    }
    
    if (leftSum == rightSum) cout << "LUCKY";
    else cout << "READY";
}
