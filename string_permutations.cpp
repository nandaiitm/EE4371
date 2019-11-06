# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    string data;
    do {
      getline(cin,data);
    }while(data.size()==0);
    sort(data.begin(),data.end());
    do{
      cout << data << " ";
    }while(next_permutation(data.begin(),data.end()));
    cout << endl;
  }

  return 0;
}
