#include <iostream>
#include <cmath>
using namespace std;
int main() {
  int t;
  cin >> t;
  while(t)
  {
    int a,b;
    cin >> a >> b;
    int diff=a^b;
    int set_bit=diff&~(diff-1);
    cout << log2(set_bit)+1 << endl;
    t--;
  }
  return 0;
}
