#include <iostream>
using namespace std;

int main()
{

  int N, K;
  int count = 0;
  
  cin >> N >> K;
  
  while (N > 1)
  {
      if (N % K > 0)
      {
          N--;
      }
      else
      {
          N /= K;
      }
      
      count++;
  }
  
  cout << count;
 
  return 0;
}
