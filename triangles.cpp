#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
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
    int count=(n*(n-1)*(n-2))/(3*2);
    int i=0,k=n-1;
    while(k>1)
    {
      while(i<k-1)
      {
        int j=i+1;
        while(j<k)
        {
          if(data[i]+data[j]<=data[k] || data[i]+data[k]<=data[j] || data[k]+data[j]<=data[i])
          {
            count--;
            j++;
          }
          else
            j++;

        }
        i++;
      }
      k--;
    }

    cout << count << endl;

  }
  return 0;
}
