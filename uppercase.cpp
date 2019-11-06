# include <iostream>
# include <string>
# include <cctype>
using namespace std;
int sumleft(int i,int *arr1);
int sumright(int j,int *arr2,int n);
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    string sentence;
    cin>>sentence;
    int count=0;
    string::iterator i;
    for(i=sentence.begin();i!=sentence.end();i++)
    {
      if(isupper(*i))
      {
        count+=1;
      }
      else
        continue;
    }
    cout << count << endl;
  }
  return 0;
}
