#include <bits/stdc++.h>
using namespace std;

int main() {
    
	while (true)
	{
        string line;
        getline(cin, line);
        
        if (line == "EOI") break;
        
        for (int i = 0; i < line.size(); i++)
        {
            line[i] = tolower(line[i]);
        }
        
        if (line.find("nemo") != string::npos) cout << "Found\n";
        else cout << "Missing\n";
	}
}
