# include <iostream>
# include <algorithm>
# include <vector>
# include <cmath>
# include <string>

using namespace std;
int main()
{
//   ios_base::sync_with_stdio(false);
//   cin.tie(NULL);
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
    int iterator=0;
    int *max;
    max=max_element(data,data+n);
    vector<int> sum_data;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(data[i]+data[j]<=*max)
            {
                sum_data[iterator]=data[i]+data[j];
                iterator++;
            }
        }
    }
    int count=0;
    for(int k=0;k<iterator;k++)
    {
        for(int m=0;m<n;m++)
        {
            if(sum_data[k]==data[m])
            {
                count++;
            }
            else
            {
                continue;
            }
            
        }
    }
    if(count>0)
    {
        cout << count << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    
    
  }
  return 0;
}





