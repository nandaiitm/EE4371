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
    string data;
    cin >> data;
    int flag=0;
    for(int i=data.size()-1;i>=0;i--)
    {
        if(data[i]=='1')
        {
            cout << i << endl;
            flag=1;
            break;
        }
        else
        {
            continue;
        }
        
    }
    if(flag==0)
    {
        cout << -1 << endl;
    }  
  }
  return 0;
}





