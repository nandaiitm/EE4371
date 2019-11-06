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
    int n,s;
    cin >> n >> s;
    int data[n];
    for(int i=0;i<n;i++)
    {
      cin >> data[i];
    }
    int start=0,iterator=0;
    int sum=0;
    for(int i=0;i<n;i++)
    {
      sum+=data[i];
    }
    if(sum<s)
    {
      cout << -1 << endl;
      continue;
    }
    sum=0;
    while(sum!=s&&iterator<n)
    {
      if(sum<s)
      {
        sum+=data[iterator];
        iterator++;
      }
      else
      {
          sum-=data[start];
          start++;
      }
      
    }
    if(sum==s)
    {
      cout << start << " " << iterator << endl;
    }
    else 
    {
      cout << -1 << endl;
    }
    
  }
  return 0;
}





