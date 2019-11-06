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
      int count=0;
      for(int j=i-(k-1);j<=i;j++)
      {

        for(int k=j+1;k<=i;k++)
        {
          if(A[j]==A[k])
          {
            count+=1;
          }
          else
            continue;
        }
      }
      cout << count << " ";
    }



  }
  return 0;
}
