# include <iostream>
# include <vector>
using namespace std;
int main()
{
  int t,n;
  cin >> t;
  while(t--)
  {
    cin >> n;
    vector<int> arr(n-1);
    for(int i=0;i<n-1;i++)
    {
      cin >> arr[i];
    }
    int sum=0,total=(n*(n+1))/2;
    for(int j=0;j<n-1;j++)
    {
      sum+=arr[j];
    }
    cout << total-sum << endl;


  }
  return 0;
}
