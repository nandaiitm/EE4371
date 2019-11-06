# include <iostream>
# include <algorithm>
# include <vector>
# include <cmath>
int josephus(int p,int q);
using namespace std;
int main()
{
  int n,k;
  cin >> n >> k;
  cout << josephus(n,k) << endl;
  return 0;
}
int josephus(int p,int q)
{
  if(p==1)
  {
    return 1;
  }
  else
  {
    return ((josephus(p-1,q)+q-1)%p+1);
  }
  
}
