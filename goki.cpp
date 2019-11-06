# include <iostream>
# include <vector>
# include <cmath>
using namespace std;
int main()
{
  int n,min;
  cin >> n >> min;
  vector<int> skill;
  skill.resize(n);
  for(int i=0;i<n;i++)
  {
    cin >> skill[i];
    if(skill[i]>=min)
    cout << "YES" << endl;
    else
    cout << "NO" << endl;
  }
  return 0;
}
