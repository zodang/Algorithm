#include <bits/stdc++.h>
using namespace std;

int main()
{
    int space = 0;
    string plans;
    
    int x = 1;
    int y = 1;
    
    // Get space value
    cin >> space;
    
    // Get plans value
    cin.ignore();
    getline(cin, plans);
    
    for (int i = 0; i < plans.length(); i++)
    {
        if (plans[i] == 'R')
        {
            if (y < space)
            {
                y++;
            }
        }
        else if (plans[i] == 'L')
        {
            if (y < 1)
            {
                y--;
            }
        }
        else if (plans[i] == 'D')
        {
            if (x < space)
            {
                x++;
            }
        }
        else if (plans[i] == 'U')
        {
            if (x < 1)
            {
                x--;
            }
        }
    }
    
    cout << x << ' ' << y;
    
    return 0;
}

