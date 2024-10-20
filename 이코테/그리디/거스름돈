#include <iostream>
using namespace std;

int main() {

    int count = 0;
    int totalMoney = 1260;
    int charges[4] = {500, 100, 50, 10};
    int answer = 0;


    for(int i = 0; i < sizeof(charges) / sizeof(charges[0]); i++)
        {
            count = totalMoney / charges[i];
            totalMoney -= charges[i] * count;
            answer += count;
        }
        
    cout << answer;
    
    return 0;
}
