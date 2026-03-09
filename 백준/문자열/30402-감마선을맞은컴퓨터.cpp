#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    string cat_name = "";
    
    while (true)
    {
        string line;
        getline(cin, line);
    
        if (line.find('w') != string::npos)
        {
            cat_name = "chunbae";
            break;
        }
        
        else if (line.find('b') != string::npos)
        {
            cat_name = "nabi";
            break;
        }
        
        else if (line.find('g') != string::npos)
        {
            cat_name = "yeongcheol";
            break;
        }
    }
    
    cout << cat_name;
}
