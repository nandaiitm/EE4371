#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int n,set_bit=0,count=0;
    cin >> n;
    if(n==0)
    {
      cout << 0 << endl;
      continue;
    }
    while(n&set_bit==0)
    {
      count++;
      set_bit<<1;

    }
    cout << count << endl;
  }
  return 0;
}
log2(n & -n) + 1;
//this code is for n>0;
