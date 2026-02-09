#include <bits/stdc++.h>
using namespace std;

int T;
int d[20][20];

int get_gold(int n, int m, const vector<vector<int>>& arr)
{
    // 1. dp 테이블 초기화
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            d[i][j] = 0;
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        d[i][0] = arr[i][0];
    }
    
    // 2. dp 진행
    for (int j = 1; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            int prev = 0;
            
            if (i-1 >= 0) prev = max(prev, d[i-1][j-1]); 
            if (i+1 < n) prev = max(prev, d[i+1][j-1]);
            prev = max(prev, d[i][j-1]);
            
            d[i][j] = prev + arr[i][j];
        }
    }
    
    // 3. 끝 열의 최대값 반환
    int max_gold = 0;
    
    for (int i = 0; i < n; i++)
    {
        max_gold = max(max_gold, d[i][m-1]);    
    }
    
    return max_gold;
}

int main() {
	cin >> T;
	
	for (int t = 0; t < T; t++)
	{
	    int x = 0;
	    int  y = 0;
	    cin >> x >> y;
	    
	    vector<vector<int>> arr(x, vector<int>(y, 0));
	    
	    for (int i = 0; i < x; i++)
	    {
	        for (int j = 0; j < y; j++)
	        {
	            int g = 0;
	            cin >> g;
	            arr[i][j] = g;;
	        }
	    }
	    
	    cout << get_gold(x, y, arr) << '\n';
	}
}
