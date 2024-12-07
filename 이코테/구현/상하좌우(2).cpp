#include <bits/stdc++.h>
using namespace std;

int main()
{
    int space = 0;
    string plans;
    
    char types[4] = {'R', 'L', 'D', 'U'};
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    int x = 1;
    int y = 1;
    
    // Get space value
    cin >> space;
    
    // Get plans value
    cin.ignore();
    getline(cin, plans);
    
    for (int i = 0; i < plans.length(); i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (plans[i] == types[j])
            {
                int nextX = x + dx[j];
                int nextY = y + dy[j];
                
                if (nextX > space || nextX < 1 || nextY > space || nextY < 1)
                {
                    break;
                }
                
                // Move
                x = nextX;
                y = nextY;
            }
        }
    }
    
    cout << x << ' ' << y;
    
    return 0;
}

