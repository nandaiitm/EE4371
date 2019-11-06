# include <iostream>
# include <sstream>
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
    string data;
    do {
      getline(cin,data);
    }while(data.size()==0);
    int i=0,flag=0;
    if(n==1)
    {
      flag=1;
    }
    while(i<n/2)
    {
      if(data[i]!=data[n-1-i])
      {

        flag=0;
        break;
      }
      else
      {
        flag=1;
        i++;

      }
    }
    if(flag==1)
    {
      cout << "Yes" << endl;
    }
    else
      cout << "No" << endl;
    }
    return 0;
  }
