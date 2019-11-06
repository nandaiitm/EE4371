# include <iostream>
# include <cmath>
# include <algorithm>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int m,n;
    cin >> m >> n;
    int k=1;
    long int count=0;
    while(k<=min(m,n))
    {
      count+=(min(m,n)-k+1)*(max(m,n)-k+1);
      k++;
    }
    cout << count << endl;
  }
  return 0;
}
