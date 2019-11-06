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
    int k=1,sum=0;
    while(n/k>0)
    {
      sum+=(n/k)%10;
      k=k*10;
    }
    cout << sum << endl;
  }
  return 0;
}
