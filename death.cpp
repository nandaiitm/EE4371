# include <iostream>
# include <vector>
using namespace std;
int main()
{
  int n,k;
  cin >> n >> k;
  vector<int> order(n);
  for(int i=0;i<n;i=i++)
  {
    order.push_back(i+1);
  }
  cout << order[3] << endl;
  return 0;
}
