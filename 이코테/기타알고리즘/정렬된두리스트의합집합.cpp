#include <bits/stdc++.h>
using namespace std;

int A, B;

int main(void)
{
    cin >> A >> B;

    vector<int> arrA, arrB, arrR;

    for (int i = 0; i < A; i++)
    {
        int a;
        cin >> a;
        arrA.push_back(a);
    }

    for (int i = 0; i < B; i++)
    {
        int b;
        cin >> b;
        arrB.push_back(b);
    }

    int i = 0; 
    int j = 0;

    while (i < A || j < B)
    {
        // A의 원소가 더 작을 때 혹은 B의 원소가 모두 처리되었을 때
        if ((arrA[i] <= arrB[j] && i < A) || j >= B)
        {
            arrR.push_back(arrA[i]);
            i++;
        }
        else 
        {
            arrR.push_back(arrB[j]);
            j++;
        }
    }
    
    for (int i = 0; i < (A + B); i++)
    {
        cout << arrR[i] << ' ';
    }
}
