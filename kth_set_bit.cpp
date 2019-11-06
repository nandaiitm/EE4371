#include <iostream>
#include <cmath>
using namespace std;
int main() {
  int t;
  cin >> t;
  while(t)
  {
    int n,k;
    cin >> n >> k;
    if((int)(n/pow(2,k))%2==1)
    {
      cout << "Yes";
    }
    else
      cout << "No";
    cout << endl;
    t--;
  }
  return 0;
}
