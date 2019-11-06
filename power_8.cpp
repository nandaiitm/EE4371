# include <iostream>
# include <cmath>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    long long int n;
    cin >> n;

    if(n==0)
    {
        cout << "NO" << endl;
        continue;
    }
    long long int set_bit;
    set_bit=n&~(n-1);
    if(n==set_bit)
    {
      int count=0;
      while(n>0)
      {
        n=n>>1;
        count++;
      }
      if((count-1)%3==0)
      {
        cout << "Yes" << endl;
      }
      else
        cout << "No" << endl;

    }
    else
      cout << "No" << endl;

  }
return 0;
}
