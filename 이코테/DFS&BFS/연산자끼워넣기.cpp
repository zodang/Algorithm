#include <bits/stdc++.h>
using namespace std;

int N;

vector<int> numArr;
int operatorArr[4];

int max_sum = -1e9;
int min_sum = 1e9;


void dfs(int depth, int sum)
{
    if (depth == N)
    {
        max_sum = max(max_sum, sum);
        min_sum = min(min_sum, sum);
        return;
    }
    
    if (operatorArr[0] != 0)
    {
        operatorArr[0] -= 1;
        dfs(depth + 1, sum + numArr[depth]);
        operatorArr[0] += 1;
    }
    
    if (operatorArr[1] != 0)
    {
        operatorArr[1] -= 1;
        dfs(depth + 1, sum - numArr[depth]);
        operatorArr[1] += 1;
    }
    
    if (operatorArr[2] != 0)
    {
        operatorArr[2] -= 1;
        dfs(depth + 1, sum * numArr[depth]);
        operatorArr[2] += 1;
    }
    
    if (operatorArr[3] != 0)
    {
        operatorArr[3] -= 1;
        dfs(depth + 1, sum / numArr[depth]);
        operatorArr[3] += 1;
    }
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
	    int n;
	    cin >> n;
	    numArr.push_back(n);
	}
	
	for (int i = 0; i < 4; i++)
	{
	    int c;
	    cin >> c;
	    operatorArr[i] = c;
	}
	
	dfs(1, numArr[0]);
	
	cout << max_sum << '\n' << min_sum;
}
