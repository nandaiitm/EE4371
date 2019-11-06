# include <iostream>
# include <vector>
# include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    vector<int> data(n);
    for(int i=0;i<n;i++)
    {
      cin >> data[i];
    }
    sort(data.begin(),data.end());
    if(n%2!=0)
    {
      for(int j=0;j<1+(n/2);j++)
      {
        if(data[j]==data[j+(n/2)])
        {
          cout << data[j] << endl;
        }
        else if(j+(n/2) == n-1)
        {
          cout << -1 << endl;
        }
        else
          continue;
      }
    }
    else
    {
      for(int j=0;j<n/2;j++)
      {
        if(data[j]==data[j+(n/2)])
        {
          cout << data[j] << endl;
          break;
        }
        else if(j+(n/2) == n-1)
        {
          cout << -1 << endl;
        }
        else
          continue;
      }
    }

  }
  return 0;
}
