# include <iostream>
# include <algorithm>
# include <vector>
# include <cmath>
long long int reverse(int);
using namespace std;
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    long long int n;
    cin >> n;
    cout << reverse(n) << endl;
  }
  return 0;
}
long long int reverse(int x)
{
  long long int k=1,size=0,revnum=0;
  vector<long long int> digits;
  while(x/k)
  {
    digits.push_back((x/k)%10);
    k=k*10;
    size++;
  }
  for(int i=0;i<size;i++)
  {
    revnum+=digits[i]*pow(10,size-i-1);
  }
  return revnum;

}
