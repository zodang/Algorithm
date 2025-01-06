#include <bits/stdc++.h>
using namespace std;

int main()
{
    string input;
    cin >> input;
    
    vector<char> resultChar;
    int resultNum = 0;
    
    for(int i = 0; i < input.size(); i++)
    {
        if (isalpha(input[i]))
        {
            // string
            resultChar.push_back(input[i]);
        }
        else
        {
            // int
            resultNum += input[i] -'0';
        }
    }
    
    sort(resultChar.begin(), resultChar.end());
    
    // print sorted string
    for (int i = 0; i < resultChar.size(); i++)
    {
        cout << resultChar[i];
    }
    
    // print sum of input
    if (resultNum > 0)
    {
        cout << resultNum;
    }
    
    return 0;
}
