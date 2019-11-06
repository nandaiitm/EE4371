#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    int data[n];
    for(int i=0;i<n;i++)
    {
      cin >> data[i];
    }
    sort(data,data+n);
    int sum=0;
    for(int j=0;j<n;j++)
    {
      if(j%2==0)
        sum+=data[j];
      else
        sum-=data[j];
    }
    cout << sum << endl;
  }
  return 0;
}
