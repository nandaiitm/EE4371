# include <iostream>
# include <string>
# include <algorithm>
using namespace std;
int main()
{
  string str1,str2,tempstr;
  getline(cin,str1);
  getline(cin,str2);

  for(int i=0;i<str1.capacity();i++)
  {
    for(int j=i;j<str2.capacity();j++)
    {
      if(str1[i]==str2[j])
      {
        swap(str2[i],str2[j]);
        break;
      }
      else
      {
        continue;
      }
    }
  }
  if(str1==str2)
  {
    cout << "YES";
  }
  else {
    cout << "NO";
  }
  return 0;
}
