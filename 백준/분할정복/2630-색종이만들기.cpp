#include <bits/stdc++.h>

using namespace std;

int N;
int blue_count = 0;
int white_count = 0;

int arr[128][128];

void Check(int x, int y, int n)
{
    int color = arr[x][y];
    bool is_same = true;
    
    for (int i = x; i < x + n; i++)
    {
        for (int j = y; j < y + n; j++)
        {
            if (arr[i][j] != color)
            {
                is_same = false;
                break;
            }
            
            if (!is_same) break;
        }
    }
    
    if (is_same)
    {
        if (color == 0) white_count += 1;
        else blue_count += 1;
        return;
    }
    
    int half = n/2;
    Check(x, y, half);
    Check(x, y + half, half);
    Check(x + half, y, half);
    Check(x + half, y + half, half);
}

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j]; 
        }
    }
    
    Check(0, 0, N);
    
    cout << white_count << '\n' << blue_count;
}
