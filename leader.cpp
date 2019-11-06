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
    int n;
    cin >> n;
    int *data=(int*) malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
    {
      cin >> data[i];
    }
    int max=data[n-1],k=0;
    vector<int> arr(n);
    for(int j=n-1;j>=0;j--)
    {
      if(data[j]>=max)
      {
        arr[k]=data[j];
        k++;
        max=data[j];
      }
      else
        continue;
    }
    arr.resize(k);
    for(int i=k-1;i>=0;i--)
    {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
