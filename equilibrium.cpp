# include <iostream>
# include <vector>
# include <bits/stdc++.h>
using namespace std;
int sumleft(int i,int *arr1);
int sumright(int j,int *arr2,int n);
void check(int a,int *arr3,int n);
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    int data[n];
    for(int i=0;i<n;i++)
    {
      cin >> data[i];
    }
    if(n==1)
    {
      cout << "1" << endl ;
    }
    else if(n==2)
    {
      cout << "-1" << endl;
    }
    else
    {
      int equi=n/2;
      check(equi,data,n);

    }

    }
    return 0;
  }

void check(int a,int *arr3,int n)
{
  if(sumleft(a,arr3)==sumright(a,arr3,n))
  {
    cout << a+1 << endl;
    return;
  }
  else
  {
    if(sumleft(a,arr3)<sumright(a,arr3,n) && sumleft(a+1,arr3)>sumright(a+1,arr3,n))
    {
      cout << "-1" << endl;
      return;
    }
    while(sumleft(a,arr3)>sumright(a,arr3,n))
    {
      check(a-1,arr3,n);
    }
    else
    {
      check(a+1,arr3,n);
    }
  }
}

int sumleft(int i,int *arr1)
{
  int sum=0;
  for(int k=0;k<i;k++)
  {
    sum+=arr1[k];
  }
  return sum;
}
int sumright(int j,int *arr2,int n)
{
  int sum=0;
  for(int k=j+1;k<n;k++)
  {
    sum+=arr2[k];
  }
  return sum;
}
