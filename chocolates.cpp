# include <iostream>
# include <algorithm>
# include <vector>
# include <cmath>
# include <string>

using namespace std;
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int n,k;
    cin >> n;
    int data[n];
    for(int i=0;i<n;i++)
    {
      cin >> data[i];
    }
    cin >> k;
    sort(data,data+n);
    if(n==0||k==0)
    {
        cout << -1 << endl;
        continue;
    }
    if(k==1)
    {
        cout << 0 << endl;
        continue;
    }
    if(n<k)
    {
        cout << -1 << endl;
        continue;
    }
    int start=0,min=data[n-1];
    int diff;
    while(start<n-k+1)
    {
        diff=data[start+k-1]-data[start];
        if(diff<=min)
        {
            min=diff;
        }
        start++;
        
    }
    cout << min << endl;


  }
  return 0;
}





