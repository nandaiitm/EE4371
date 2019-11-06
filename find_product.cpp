# include <iostream>
# include <vector>
# include <cmath>
using namespace std;
int main()
{
  int size,rem=1;
  cin >> size;
  vector<long long int> arr;
  arr.resize(size);
  for(long long int i=0;i<size;i++)
  {
    cin >> arr[i];
    long long int z=pow(10,9)+7;
    rem=(rem*arr[i])%z;
  }
  cout << rem << endl;
  return 0;
}
