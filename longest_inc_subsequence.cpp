# include <iostream>
# include <algorithm>
# include <vector>
# include <cmath>
# include <string>

using namespace std;
int longest_subsequence(int *arr,int size)
{
    int lis[size];
    lis[0]=1;
    for(int i=0;i<size;i++)
    {
        lis[i]=1;
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j]&&lis[i]<lis[j]+1)
            {
                lis[i]=lis[j]+1;
            }
        }
    }
    return *max_element(lis,lis+size);
}

int main()
{
//   ios_base::sync_with_stdio(false);
//   cin.tie(NULL);
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
    cout << longest_subsequence(data,n) << endl;
    
  }
  return 0;
}





