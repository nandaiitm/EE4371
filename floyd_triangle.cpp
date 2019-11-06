#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    int k=1,z=1;
    while(k<=n)
    {
      int m=k;
      while(m>0)
      {
        cout << z << " ";
        z++;
        m--;
      }
      cout << endl;
      k++;
    }
  }
  return 0;
}
