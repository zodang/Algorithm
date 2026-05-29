#include <bits/stdc++.h>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> char_stack;

    // '('이면 stack에 넣기, ')'이면 stack에서 빼기
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(') char_stack.push(s[i]);
        else
        {
            if (char_stack.size() == 0) answer = false;
            else char_stack.pop();
        }
    }
    
    if (char_stack.size() > 0) answer = false;
    return answer;
}
