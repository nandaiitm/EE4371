#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    string data;
    cin >> data;
    int k=data.size();
    while(k>0)
    {
      cout << data << endl;
      data.pop_back();
      data.resize(k-1);
      k--;
    }

  }
  return 0;
}
