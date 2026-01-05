#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
	
	cin >> N;
	string strN = to_string(N);
	
	int left = 0;
	int right = 0;
	
	for (int i = 0; i < strN.size(); i++)
	{
	    // 1. 각 자리 숫자 변환
	    int currentValue = strN[i] - '0';
	    
	    // 2. 왼쪽과 오른쪽의 각각 합 구하기
	    if (i < strN.size() / 2) left += currentValue;
	    else right += currentValue;
	}
	
	// 3. 비교 후 출력력
	if (left == right) cout << "LUCKY";
	else cout << "READY";
}
