# include <iostream>
# include <cmath>
# include <string>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    string s;
    do {
      getline(cin,s);
    }while(s.size()==0);
    int bin=stoi(s);
    int k=1,num=0;
    int size=s.size();
    while(size)
    {
      num+=pow(2,(bin/k)%10);
      k=k*10;
      size-=1;
    }
    int m=1,sum=0;
    while(num/m)
    {
      sum+=(num/m)%10;
      m=m*10;
    }
    if(sum%3==0)
    {
      cout << 1 << endl;
    }
    else
      cout << 0 << endl;


  }
  return 0;
}
