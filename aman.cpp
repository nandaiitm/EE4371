# include <iostream>
# include <vector>
# include <cmath>
using namespace std;
int main()
{
  int days,horlicks,radius,toffee=0;
  cin >> days;
  for(int i=0;i<days;i++)
  {
    vector<float> arr(2);
    for(int j=0;j<2;j++)
    {
      cin >> arr[j];
    }
    if(float(2*22*arr[0]/7) <= 100*arr[1])
    {
      toffee+=1;
    }
    else
    {
      continue;
    }
    arr.clear();
  }
  cout << toffee << endl;
  return 0;
}
