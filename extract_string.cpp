#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
  int t;
	cin>> t;

  while(t--)
  {
    string s1;
    do{
      getline(cin ,s1);
    }while(s1.size()==0);
  	bool flag=false;
    string k;
    int count=0;
    for(int i=0;i<s1.size();i++)
    {
      flag=false;
      while(48<=s1[i]&&s1[i]<=57&&i<s1.size())
      {
        flag=true;
        k=k+s1[i];
        count++;
        i++;
      }
      if(flag)
      {
        cout << k << " ";
        k.resize(0);
      }
    }
    if(count==0)
    {
      cout << "No Integers" << endl;
    }
    else
      cout << endl;

  }

  return 0;
}
