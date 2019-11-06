#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
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
    int *max,*min;
    max=std::max_element(data,data+n);
    min=std::min_element(data,data+n);
    cout << *max << " " << *min << endl;
  }
  return 0;
}
