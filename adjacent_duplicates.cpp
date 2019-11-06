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
    do {
      getline(cin,data);
    }while(data.size()==0);
    char temp;
    for(int i=0;i<data.size()-1;i++)
    {
        if(data[i]==data[i+1])
        {
          temp=data[i];
        }
        if(temp==data[i])
        {
          data.erase(data.begin()+i,)
        }
    }
  }
  return 0;
}
