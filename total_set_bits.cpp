#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while(t)
  {
    int n;
    cin >> n;
    int count=0;
    while(n)
    {
      int set_bit;
      int k=n;
      while(k>0)
      {
        set_bit=k&~(k-1);
        count++;
        k=k-set_bit;

      }
      n--;
    }
    cout << count << endl;
    t--;
  }
  return 0;
}
