# include <iostream>
# include <algorithm>
# include <cmath>

bool isadjacent(int);
bool islessthan(int val,int y);
using namespace std;
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int n,k;
    cin >> n >> k;
    int data[n];
    for(int i=0;i<n;i++)
    {
      cin >> data[i];
    }
    int flag=0;
    for(int j=0;j<n;j++)
    {
      if(isadjacent(data[j]))
      {
        if(islessthan(data[j],k))
        {
          cout << data[j] << " ";
          flag=1;
        }
        else
          continue;
      }
      else
        continue;
    }
    if(flag==0)
    {
        cout << "-1" << endl;
    }
    else
        cout << endl;
  }
  return 0;
}

bool isadjacent(int x)
{
  int k=1,size=0;
  while(x/k)
  {
    k=k*10;
    size++;

  }
  if(size==1)
  {
    return false;

  }
  int digits[size];
  for(int j=1;j<size;j++)
  {

    if(abs(digits[j]-digits[j-1])!=1)
    {
      return false;

    }
    else
      continue;
  }
  return true;

}

bool islessthan(int val,int y)
{
  if(val<y)
  {
    return true;
  }
  else
    return false;
}
