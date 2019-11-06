# include <iostream>
# include <sstream>
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
    string data;
    do {
      getline(cin,data);
    }while(data.size()==0);
    stringstream ss(data);
    int a,b,c,d;
    char x;
    ss >> a >> x >> b >> x >> c >> x >> d >> x;
    cout << a << " " << b << " " <<  c << " " << d << endl;
  }
  return 0;
}
