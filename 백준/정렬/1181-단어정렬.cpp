#include <bits/stdc++.h>
using namespace std;

int N;
vector<string> arr;

bool SortWord(const string& w1, const string& w2)
{
    if (w1.size() == w2.size()) return w1 < w2;
    return w1.size() < w2.size();
}

int main() {
	
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
	    string word;
	    cin >> word;
	    arr.push_back(word);
	}
	
	sort(arr.begin(), arr.end(), SortWord);
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	
	for (int i = 0; i < arr.size(); i++)
	{
	    cout << arr[i] << '\n';
	}
}
