# include <iostream>
# include <string>
# include <cctype>
using namespace std;
int main()
{
  string input,output;
  cin >> input;
  input.resize(input.size());
  for(int j=0;j<input.capacity();j++)
  {
    if(isupper(input[j]))
    {
      output.push_back(tolower(input[j]));
    }
    else if(islower(input[j]))
    {
      output.push_back(toupper(input[j]));
    }
    else
    {
      continue;
    }
  }
  output.resize(input.size());
  cout << output << endl;
  return 0;
}
