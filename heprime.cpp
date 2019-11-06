#include <iostream>
using namespace std;
bool isprime(int);
int main()
{
  int n;
  cin >> n;
  for(int i=1;i<=n;i++)
  {
    if(isprime(i))
    {
      cout << i << " ";
    }
  }
  cout << endl;
  return 0;
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
    return 0;
  }
}
