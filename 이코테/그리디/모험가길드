#include <iostream>
using namespace std;

int main()
{
    int N;
    int S[100000];
    
    int result = 0;
    
    // Input
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> S[i];
    }
    
    for (int i = 1; i <= N; i++)
    {
        int count = 0;
        
        for(int j = 0; j < N; j++)
        {
            if (S[j] == i)
            {
                count++;
            }
        }
        
        result += count / i;
    }
    
    cout << result;

    return 0;
}
