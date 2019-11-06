# include <iostream>
# include <algorithm>
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
    int count=0;
    for(int i=0;i<data.size();i++)
    {
      if(data[i]=='.')
      {
        count++;
      }
      else
        continue;
    }
    vector<string> words;
    string alphabets;

    for(int i=0;i<data.size();i++)
    {
      if(data[i]=='.')
      {
        words.push_back(alphabets);
        alphabets.clear();
      }
      else
        alphabets.push_back(data[i]);
    }
    words.push_back(alphabets);
    for(int j=0;j<words.size();j++)
    {
      cout << words[count-j];
      if(j==words.size()-1)
      {
        cout << endl;
      }
      else
        cout << '.';
    }

  }
  return 0;
}
