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
    int temp_flag=0;
    vector <int> buysell;
    for(int j=1;j<n;j++)
    {
      if(data[j]>data[j-1])
      {
        if(temp_flag==0)
        {
          buysell.push_back(j-1);
          temp_flag=1;
        }
        else
        {
          temp_flag=1;
          continue;
        }  
      }
      if(data[j]<data[j-1])
      {
        if(temp_flag==1)
        {
          buysell.push_back(j-1);
          temp_flag=0;
        }
        else
        {
          temp_flag=0;
          continue;
        }  
      }  
    }
    if(temp_flag==1)
    {
      buysell.push_back(n-1);
    }
    // buysell.shrink_to_fit();
    if(buysell.size()==0)
    {
      cout << "No Profit";
    }
    else
    {
        for(int k=1;k<buysell.size();k=k+2)  
        {
            cout << "(" << buysell[k-1] << " " <<  buysell[k] << ")" << " ";
        }
    }
    cout << endl; 
  }
  return 0;
}





