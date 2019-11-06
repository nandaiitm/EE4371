# include <iostream>
# include <algorithm>
# include <vector>
# include <cmath>
# include <string>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    vector<int> data(n);
    for(int i=0;i<n;i++)
    {
      cin >> data[i];
    }
    int it=2;
    while(it<n)
    {
            if(it%2==0)
            {
        
            if(data[it-1]<data[it-2])
            {
                swap(data[it-2],data[it-1]);
            }
            if(data[it-1]<data[it])
            {
                swap(data[it],data[it-1]);
            }
        
            }
            if(it%2==1)
            {
        
        
            if(data[it-1]>data[it-2])
            {
                swap(data[it-2],data[it-1]);
            }
            if(data[it-1]>data[it])
            {
                swap(data[it],data[it-1]);
            }
        
            }
        it++;
    }
    
    for(int i=0;i<n;i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
  }
  return 0;
}





