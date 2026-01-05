#include <bits/stdc++.h>
using namespace std;

string S;

int main() {
    cin >> S;
    
    vector<char> charArr;
    int intSum = 0;
    
    for (int i = 0; i < S.size(); i++)
    {
        int currentS = S[i] - '0';
        
        // 1. 문자숫자 구분 (if (currentS > 9))
        if (isalpha(S[i])) charArr.push_back(S[i]);
        else intSum += currentS;
    }
    
    // 2. 문자열 정렬 후 출력
    sort(charArr.begin(), charArr.end());
    
    for (int i = 0; i < charArr.size(); i++)
    {
        cout << charArr[i];
    }
    
    // 3. 숫자 합 출력
    if (intSum > 0) cout << intSum;
}
