#include <iostream>
using namespace std;
bool isprime(int x);
int main()
{
  int y=4;
  cout << isprime(y);
}



bool isprime(int x)
{
  int sum=0;
  for(int i=1;i<=x;i++)
  {
    if(x%i==0)
    {
      sum+=i;
    }
  }
  if(sum==x+1)
  {
    return true;
  }
  else
  {
    return false;
  }
}
