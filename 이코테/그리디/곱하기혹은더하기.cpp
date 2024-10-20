#include <iostream>
#include <string>
using namespace std;

int main()
{
    string S;
    cin >> S;
    
    int result = 0;
    
    for(int i = 0; i < S.length(); i++)
    {
        int value = S[i] - '0';
        
        // 0 혹은 1일 때는 곱하는 것보다 더하는 것이 효율적
        if (value <= 1)
        {
            result += value;
            
        }
        else
        {
            // 첫 문자가 0일 때의 예외처리
            if (result == 0)
            {
                result = 1;
            }
            
            result *= value;
        }
    }
    
  cout << result;
  return 0;
}
