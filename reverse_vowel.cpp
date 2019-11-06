# include <iostream>
# include <algorithm>
# include <vector>
# include <cmath>
# include <string>
using namespace std;
bool isvowel(char x);
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
    vector<char> input;
    for(int i=0;i<data.size();i++)
    {
      input.push_back(data[i]);
    }
    input.shrink_to_fit();
    vector<char> vowels;
    for(int i=0;i<input.size();i++)
    {
      if(isvowel(input[i]))
      {
        vowels.push_back(input[i]);
      }
      else
        continue;
    }
    vowels.shrink_to_fit();
    vector<char> result;
    int temp=vowels.size()-1;
    for(int i=0;i<input.size();i++)
    {
      if(isvowel(input[i]))
      {
        result.push_back(vowels[temp]);
        temp--;
      }
      else
        result.push_back(input[i]);
    }


    for(int i=0;i<result.size();i++)
    {
      cout << result[i];
    }
    cout << endl;

  }
  return 0;
}

bool isvowel(char x)
{
  if(x=='a'|| x=='e' || x=='i' || x=='o' || x=='u')
  {
    return true;
  }
  else
    return false;
}
