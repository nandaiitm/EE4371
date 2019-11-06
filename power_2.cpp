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

    }
    else
    {
      long long int set_bit;
      set_bit=n&~(n-1);
      if(n==set_bit)
      {
          cout << "YES" << endl;
      }
      else
        cout << "NO" << endl;

    }

  }
return 0;
}
