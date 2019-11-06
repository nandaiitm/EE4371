#include <iostream>
using namespace std;
int oppseat(int);
int main()
{
  int seat,coach,t;
  cin >> t;
  while(t--)
  {
    cin >> seat;
    int tempseat=seat%12;
    if(tempseat==0)
    {
      coach=(seat/12)-1;
    }
    else
    {
      coach=(seat/12);
    }
    int tempoppseat=oppseat(tempseat);
    int opposite_seat=oppseat(tempseat)+coach*12;
    cout << opposite_seat << " ";
    if(tempoppseat==12||tempoppseat==1||tempoppseat==6||tempoppseat==7)
    {
      cout << "WS" << endl;
    }
    else if(tempoppseat==11||tempoppseat==2||tempoppseat==5||tempoppseat==8)
    {
      cout << "MS" << endl;;
    }
    else
    {
      cout << "AS" << endl;
    }
  }

  return 0;

}

int oppseat(int x)
{
  if(x==1)
  {
    return 12;
  }
  else if(x==0)
  {
    return 1;
  }
  else
  {
    return 13-x;
  }
}
