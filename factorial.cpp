# include <iostream>
using namespace std;
int factorial(int);
int main()
{
  int n;
  cin >> n;
  cout << factorial(n) << endl;
  return 0;
}
int factorial(int x)
{
  if(x>0)
  {
    return x*factorial(x-1);
  }
  else
  {
    return 1;
  }
}
