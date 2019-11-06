#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin >> n;
  for(int i=1<<13;i>0;i=i/2)
  {
    if(n&i)
    {
      cout << "1";
    }
    else
      cout << "0";
  }
  cout << endl;


  return 0;
}
