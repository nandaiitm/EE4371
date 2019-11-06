# include <iostream>
# include <vector>
#include <algorithm>
# include <cstdlib>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int n,k;
    cin >> n >> k;
    int *data=(int*) malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
    {
      cin >> data[i];
    }
    int *p;
    for(int j=k;j<=n;j++)
    {
      p=std::max_element(data+j-k,data+j);
      cout << *p << " ";

    }

    cout << endl;
  }
  return 0;
}
