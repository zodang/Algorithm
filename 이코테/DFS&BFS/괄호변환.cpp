#include <bits/stdc++.h>
using namespace std;

// 올바른 괄호 문자열 여부 반환
int is_correct(string str)
{
    stack<char> s;
    
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(') s.push(str[i]);
        else if (s.size() > 0 && str[i] == ')') s.pop();
    }
    
    if (s.size() == 0) return true;
    else return false;
}

// 문자열 분리
pair<string, string> seperate(string str)
{
    int sum = 0;
    int idx = 0;
    
    for (idx = 0; idx < str.size(); idx++)
    {
        if (str[idx] == '(') sum += 1;
        else if (str[idx] == ')') sum -= 1;
        
        if (sum == 0) break;
    }
    
    string u = str.substr(0, idx+1);
    string v = str.substr(idx+1);
    
    return {u, v};
}

string recursive(string str)
{
    // 1. 빈 문자열 반환
    string result = "";
    if (str == "") return result;
    
    // 2. 문자열 w를 u, v로 분리
    pair<string, string> seperated_str = seperate(str);
    string u = seperated_str.first;
    string v = seperated_str.second;
    
    // 3. u가 올바른 괄호 문자열인 경우
    if (is_correct(u)) return u + recursive(v);
    
    // 4. u가 올바른 괄호 문자열이 아닌 경우
    result += '(';
    result += recursive(v);
    result += ')';
    u = u.substr(1, u.size() - 2); 
       
    for (int i = 0; i < u.size(); i++)
    {
        if (u[i] == '(') u[i] = ')';
        else if (u[i] == ')') u[i] = '(';
    }
    
    return result += u;
}

string solution(string p) {
    string answer = recursive(p);
    return answer;
}
