# include <iostream>
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
    vector<int> bindata(32);
    for(int i=bindata.size()-1;i>=0;i++)
    {
      bindata.push_back((int)(n/pow(2,i))%2);
    }
    int revbitnum=0;
    for(int i=0;i<32;i++)
    {
      revbitnum+=bindata[i]*pow(2,i);
    }
    cout << revbitnum << endl;
  }
  return 0;
}
