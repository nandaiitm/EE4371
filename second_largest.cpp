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
    vector<int> data(n);
    for(int i=0;i<n;i++)
    {
      cin >> data[i];
    }
    int* first_max;
    first_max=std::max_element(data.begin(),data.end());
    int* sec_max;
    sec_max=std::min_element(data.begin(),data.end());
    int next_max = *sec_max;
    for(auto j=data.begin();j!=data.end();j++)
    {
      while(*j!=*first_max)
      {
        if(*j>next_max)
        {
          next_max=*j;
        }
        else
          break;
      }
    }
    cout << next_max << endl;


  }
  return 0;


}
