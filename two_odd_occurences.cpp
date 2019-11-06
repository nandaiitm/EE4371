#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {

  int data[] = {4, 2, 4, 5, 2, 3, 3, 1};
  int n = sizeof(data)/sizeof(data[0]);
    int xy=0,x=0,y=0;
    for(int i=0;i<n;i++)
    {
      xy=xy^data[i];
    }
    int set_bit;
    set_bit=xy&~(xy-1);
    for(int j=0;j<n;j++)
    {
      if(data[j]&set_bit)
      {
        x=x^data[j];
      }
      else
        y=y^data[j];

    }
    cout << x << "&" << y << endl;

  return 0;
}
