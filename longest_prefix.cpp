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

    string data1,data2;
    cin >> data1 >> data2;
    int count=0;

    for(int j=0;j<data2.size();j++)
    {
      if(data1[0]==data2[j])
      {
        count++;
      }
      else
      {
        continue;
      }

    }
    int i,temp=0;
    if(count==1)
    {
      for(i=0;i<data2.size();i++)
      {
        if(data2[i]==data1[0])
        {
          break;
        }
        else
          continue;
      }
      cout << i << " ";
      while(data1[temp]==data2[i])
      {
        cout << data2[i] << " ";
        temp++;
        i++;
      }
      cout << endl;
    }


    else if(count>1)
    {
      vector<string> probables(count);
      int m=0;
      while(count--)
      {
        while(data2[m]!=data1[0])
        {
          m++;
        }
        if()
      }
    }
    else
      cout << "-1" << endl;

  }
  return 0;
}
