#include <bits/stdc++.h>
using namespace std;

string Hand;
pair<int, int> currentL= {3, 0};
pair<int, int> currentR {3, 2};
pair<int, int> currentK;

int distanceL = 0;
int distanceR = 0;
char movingHand = ' ';

char GetCurrentHand(int x, pair<int, int> currentK)
{
    if (x == 1 || x == 4 || x == 7) 
    {
        currentL = currentK;
        return 'L';
    }
    if (x == 3 || x == 6 || x == 9)
    {
        currentR = currentK;
        return 'R';
    }
    
    // 거리 계산
    distanceL = abs(currentK.first - currentL.first) + abs(currentK.second - currentL.second);
    distanceR = abs(currentK.first - currentR.first) + abs(currentK.second - currentR.second);
        
    // 손잡이와 거리에 따라 움직일 손 구분
    if (distanceL == distanceR) movingHand = (Hand == "right") ? 'R' : 'L' ;
    else movingHand = (distanceL > distanceR) ? 'R' : 'L';

    // 움직인 손 위치 업데이트
    if (movingHand == 'R') currentR = currentK;
    else currentL = currentK;
    
    return movingHand;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    Hand = hand;
    
    // keypad 좌표 초기화
    vector<pair<int, int>> keypad;
    
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            keypad.push_back({i, j});
        }
    }
    
    char num = ' ';
    for (int i = 0; i < numbers.size(); i++)
    {
        // 누를 숫자 구분
        if (numbers[i] == '*' - '0') currentK = keypad[9];
        else if (numbers[i] == 0) currentK = keypad[10];
        else if (numbers[i] == '#' - '0') currentK = keypad[11];
        else currentK = keypad[numbers[i]-1];
        
        num = GetCurrentHand(numbers[i], currentK);
        answer.push_back(num);
    }
    
    return answer;
}
