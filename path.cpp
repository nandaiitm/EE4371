#include <iostream>
using namespace std;
long long int fact(int);

int main()
{
  short int t;
  cin >> t;
  while(t--)
  {
    short int m,n;
    cin >> m >> n;
    long long  int count;
    count=fact(m-1+n-1)/(fact(m-1)*fact(n-1));
    cout << count;
    cout << endl;
  }
  return 0;
}
long long int fact(int n)
{
  if(n==0)
    return 1;
  else
    return n*fact(n-1);
}
