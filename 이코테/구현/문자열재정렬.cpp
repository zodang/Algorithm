#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main()
{
    string input;
    cin >> input;
    
    string outputString;
    int outputInt = 0;
    
    for(int i = 0; i < input.length(); i++)
    {
        if (input[i] -'9' > 0)
        {
            // string
            outputString += input[i];
        }
        else
        {
            // int
            outputInt += input[i] -'0';
        }
    }
    
    sort(outputString.begin(), outputString.end());
    
    if (outputInt == 0)
    {
        cout << outputString;
    }
    else
    {
        cout << outputString <<  outputInt;
    }
    
    
    return 0;
}
