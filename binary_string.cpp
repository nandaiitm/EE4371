# include <iostream>
# include <algorithm>
# include <vector>
# include <cmath>
# include <string>
using namespace std;
bool isvowel(char x);
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
    int count=0;
    for(int i=0;i<data.size();i++)
    {
      if(data[i]=='1')
      {
        count++;
      }
      // else
      //   continue;
    }
    cout << (count*(count-1))/2 << endl;
  }
  return 0;
}
