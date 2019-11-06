#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    vector <int>v;
    v.clear();
    for(int i=1;i<=sqrt(n);i++)
    {
      if(n%i==0)
      {
        if(i==n/i)
        {
          v.push_back(i);
        }
        else
        {
          v.push_back(i);
          v.push_back(n/i);
        }
      }
      else
        continue;
    }
    cout << v.size() << endl;
  }
  return 0;
}
