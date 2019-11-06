#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    vector<int> digits;
    int k=1,sum=0;
    while(n/k>0)
    {
      digits.push_back((n/k)%10);
      k=k*10;
    }
    digits.shrink_to_fit();
    int order=digits.size();
    for(int i=0;i<order;i++)
    {
      sum+=pow(digits[i],order);
    }
    if(sum==n)
    {
      cout << "Yes";
    }
    else
      cout << "No";
  }
  return 0;
}
