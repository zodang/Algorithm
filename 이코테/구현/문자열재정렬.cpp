#include <bits/stdc++.h>
using namespace std;

string S;

int main(void)
{
    cin >> S;
    
    vector<char> vec;
    int sum = 0;
    
    for (int i = 0; i < S.size(); i++)
    {
        // 문자 숫자 구분
        if (isalpha(S[i])) vec.push_back(S[i]);
        else if (isdigit(S[i])) sum += S[i] - '0';
    }
    
    sort(vec.begin(), vec.end());
    
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i];
    }
    
    if (sum > 0) cout << sum;
}
