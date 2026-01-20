#include <bits/stdc++.h>
using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> cards;

int main() {
	cin >> N;
	long long count = 0;
	
	for (int i = 0; i < N; i++)
	{
	    int x;
	    cin >> x;
	    cards.push(x);
	}
	
	while (true)
	{
	    int c1 = cards.top();
	    cards.pop();
	    
	    if (cards.size() == 0) break;
	    
	    int c2 = cards.top();
	    cards.pop();
	    
	    int c = c1 + c2;
	    cards.push(c);
	    
	    count += c;
	}
	
	cout << count;
}
