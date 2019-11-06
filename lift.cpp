# include <iostream>
# include <cmath>
using namespace std;
int main()
{
  int t;
  cin >> t;
  int n,a=0,b=7;
  while(t>0)
  {
    cin >> n;
    if(abs(n-a)<=abs(n-b))
    {
      cout << "A" << endl;
      a=n;
    }
    else
    {
      cout << "B" << endl;
      b=n;
    }
    t--;
  }
  return 0;
}
