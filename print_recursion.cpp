#include <iostream>
using namespace std;
void print(int);

int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    print(n);
    cout << endl;
  }
  return 0;
}
void print(int x)
{
  cout << x << " ";
  if(x>0)
  {
    print(x-5);
  }
  else
  {
    return;
  }
  cout << x << " ";
}
