#include <iostream>
#include <cstdio>
using namespace std;
int main(){
  int n,round=1;
  cin >> n;
  while( 3*round*(round+1)/2 < n){
    round++;
  }
  int remain = n -3*round*(round+1)/2+3*round;

  if(round >= remain)
  {
    if(remain==0)
    {
      cout << "Motu";
    }
    else
    {
      cout << "Patlu";
    }
  }
  else
  {
    cout << "Motu";
  }
  return 0;
}
