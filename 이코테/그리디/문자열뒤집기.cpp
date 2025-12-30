#include <bits/stdc++.h>
using namespace std;

string S;

int count0;
int count1;

int main(void) {
    cin >> S;
    
    char currentC = ' ';
    
	for (int i = 0; i < S.size(); i++)
	{
	    if (S[i] == '0' && currentC != '0')
	    {
	        count0++;
	        currentC = '0';
	    }
	    else if (S[i] == '1' && currentC != '1')
	    {
	        count1++;
	        currentC = '1';
	    }
	}
	
    if (count0 <= count1) cout << count0;
    else cout <<count1;
}
