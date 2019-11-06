#include <iostream>
# include <sstream>
#include <vector>
#include <cstdlib>
using namespace std;
int main()
{
   string s1;
   getline(cin,s1);
   char a;
   vector<int> data(s1.size());
   stringstream ss(s1);
   while(ss>>a)
   {
     data.push_back(a);
   }
   cout << data[4] << endl;
   return 0;

}
