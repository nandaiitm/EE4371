# include <iostream>
# include <cmath>
bool isPrime(int n);
using namespace std;
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    int total=0;
    for(int i=2;i<=n;i++)
    {
      if(isPrime(i))
      {
        total+=i;
      }
      else
        continue;
    }
    cout << total << endl;
  }
return 0;
}

bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;

    // Check from 2 to n-1
    for (int i = 2; i < 1+(n/2); i++)
        if (n % i == 0)
            return false;

    return true;
}
