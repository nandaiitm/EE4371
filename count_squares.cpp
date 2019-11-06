# include <iostream>
# include <algorithm>
# include <vector>
# include <cmath>
# include <string>
# include <cctype>

using namespace std;
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
     
    long long int n;
    cin >> n;
    long double lognum=(log10(n))/2;
    long double num=pow(10,lognum);
    if(num-(long long int)num<0.00001)
    {
        cout << num-1 << endl;
    }
    else
        cout << floor(num) << endl;
        
        
    
    
    
  }
  return 0;
}





