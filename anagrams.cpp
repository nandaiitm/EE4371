# include <iostream>
# include <string>
# include <algorithm>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    string str1,str2;
    cin >> str1;
    cin >> str2;
    for(auto itr=str1.begin();itr!=str1.end();itr++)
    {
      for(auto its=str2.begin();its!=str2.end();its++)
      {
        if(*itr==*its)
        {
          str2.erase(its);
          str1.erase(itr);
          break;
        }
        else
        {
          continue;
        }
      }
    }
    cout << str1.size()+str2.size() << endl;
  }

  return 0;
}
