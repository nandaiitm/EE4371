# include <iostream>
# include <string>
using namespace std;

int main()
{
  string str1;
  cin >> str1;
  int xsum=0,ysum=0;
  for(int i=0;i<str1.capacity();i++)
  {
    if(str1[i]=='L')
    {
      xsum += -1;
    }
    else if(str1[i]=='R')
    {
      xsum += 1;
    }
    else if(str1[i]=='D')
    {
      ysum += -1;
    }
    else if(str1[i]=='U')
    {
      ysum += 1;
    }
    else
    {
      continue;
    }
  }
  cout << xsum << endl;
  cout << ysum << endl;
  return 0;


}
