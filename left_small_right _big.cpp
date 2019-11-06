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
    int n;
    cin >> n;
    int data[n];
    for(int i=0;i<n;i++)
    {
      cin >> data[i];
    }
    int it=1,temp_flag=0;
    while(it<n-1)
    {
      for(int j=0;j<it;j++)
      {
        if(data[j]<=data[it])
        {
          temp_flag=1;
          continue;
        }
        else
        {
          temp_flag=0;
          break;
        }
      }
      if(temp_flag==1)
      {
        for(int k=n-1;k>it;k--)
        {
          if(data[k]>=data[it])
          {
            temp_flag=1;
            continue;
          }
          else
          {
            temp_flag=0;
            break;
          }  
        }
      }
      if(temp_flag==1)
      {
        break;
      }
      else
      {
        it++;
      }  
    }
    if(temp_flag==0)
    {
      cout << -1 << endl;
    }
    else
    {
      cout << data[it] << endl; 
    }
    
  }
  return 0;
}





