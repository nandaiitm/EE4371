# include <iostream>
# include <cmath>
# include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int n,k;
    cin >> n >> k;
    int *data=(int*) malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
    {
      cin >> data[i];
    }
    for(int i=k-1;i<n;i++)
    {
      for(int j=i-(k-1);j<=i;j++)
      {

      }
    }

  }
  return 0;
}
