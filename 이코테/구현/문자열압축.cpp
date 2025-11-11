#include <bits/stdc++.h>
using namespace std;

int solution(string s) {
    int answer = 1000;

    for (int i = 1; i <= s.size(); i++)
    {
        vector<string> vec;
        int count = 0;
        
        while (count < s.size())
        {
            // i개씩 문자열 자르기
            string x = s.substr(count, i);
            vec.push_back(x);
            count += i;
        }
        
        // 같은 문자 비교 및 카운트를 위한 세팅
        int sameCount = 0;
        string currentText = vec[0];
        string resultText = "";
        
        for (int k = 0; k < vec.size(); k++)
        {
            if (currentText == vec[k]) 
            {
                // 같은 경우 숫자 카운트
                sameCount++;
            }
            else
            {
                // 현재까지의 sameCount와 currentText까지 작성
                if (sameCount == 1) resultText += currentText;
                else resultText += (to_string(sameCount) + currentText);
                
                // currentText 갱신
                currentText = vec[k];
                sameCount = 1;
            }
        }
        
        // 마지막 sameCount와 currentText 작성
        if (sameCount == 1) resultText += currentText;
        else resultText += (to_string(sameCount) + currentText);
        
        // 최소값 갱신
        if (answer > resultText.size()) answer = resultText.size();
    }
    
    return answer;
}
