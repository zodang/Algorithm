#include <bits/stdc++.h>
using namespace std;

int solution(string s) {
    int answer = 1000;
    
    for (int n = 1; n <= s.size(); n++)
    {
        string resultS = "";
        
        // 1. 첫 문자열 자르기
        int count = 1;
        string prevS = s.substr(0, n);
        
        for (int j = n; j < s.size(); j += n)
        {
            // 2. 두번째 문자열 잘라서 비교
            string currentS = s.substr(j, n);
            
            if (prevS == currentS) count++;
            else 
            {
                // 3. 다른 문자열 등장 시, 이전까지의 개수와 문자열 추가
                if (count == 1) resultS += prevS;
                else resultS += to_string(count) + prevS; 
                
                count = 1;
                prevS = currentS;
            }
        }
        
        // 4. n개로 자른 뒤 남은 문자열 추가
        if (count == 1) resultS += prevS;
        else resultS += to_string(count) + prevS;
        
        // 5. 최소 문자열 개수 갱신
        if (answer > resultS.size()) answer = resultS.size();
    }
    
    return answer;
}
