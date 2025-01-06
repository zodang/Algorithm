#include <bits/stdc++.h>
using namespace std;

int Move(int a, int b)
{
    int result = 0;
    
    int xList[8]  = {-2, -2, -1, -1, 1, 1, 2, 2};
    int yList[8]  = {1, -1, 2, -2, 2, -2, 1, -1};
    
    for (int i = 0; i < 8; i++)
    {
        if (a + xList[i] > 0 && a + xList[i] < 8)
        {
            if (b + yList[i] > 0 && b + yList[i] < 8)
            {
                result++;
            }
        }
    }
    
    return result;
}

int main()
{
    string input;
    int output;
    char x[] = {'a','b','c','d','e','f','g','h'};
    char y[] = {'1','2','3','4','5','6','7','8'};
    
    getline(cin, input);
    
    cout << "input1: " << input[0] << " input2: " << input[1] << "\n";
    
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (x[i] == input[0] && y[j] == input[1])
            {
                
                output = Move(i, j);
            }
        }
    }
    
    cout << output;
    
    return 0;
}
