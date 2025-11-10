#include <bits/stdc++.h>
using namespace std;

string S;

int main() {
    
    cin >> S;
    
    int count0 = 0;
    int count1 = 0;
    
    char checkingNum = S[0];
    
    if (S[0] == '0') count0++;
    else count1++;  
    
    for (int i = 1; i < S.size(); i++)
    {
        if (checkingNum != S[i])
        {
            checkingNum = S[i];
            
            if (S[i] == '0') count0++;
            else count1++;  
        }
    }
    
    cout << min(count0, count1);
}
