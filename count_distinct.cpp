#include <iostream>
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
    int data[n];
    for(int i=0;i<n;i++)
    {
      cin >> data[i];
    }

    for(int j=0;j<=n-k;j++)
    {
      int dupdata[k];
      for(int i=0;i<k;i++)
      {
        dupdata[i]=data[j+i];
      }
      sort(dupdata,dupdata+k);
      int count=k;
      for(int x=0;x<k-1;x++)
      {
        if(dupdata[x]-dupdata[x+1]==0)
        {
          count-=1;
        }
        else
          continue;
      }
      cout << count << " ";
    }
    cout << endl;
  }
  return 0;
}
