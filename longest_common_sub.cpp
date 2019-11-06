# include <iostream>
# include <algorithm>
# include <vector>
# include <cmath>
# include <string>

using namespace std;
int max(int a, int b) 
{ 
    return (a > b)? a : b; 
} 
int longest_subsequence(string str1,string str2)
{
    int m=str1.size(),n=str2.size();
    int table[m+1][n+1];
    int i,j;
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0||j==0)
            {
                table[i][j]=0;
            }
            else if(str1[i-1]==str2[j-1])
            {
                table[i][j]=table[i-1][j-1]+1;
            }
            else
            {
                table[i][j]=max(table[i-1][j],table[i][j-1]);
            }
        }
    }
    return table[m][n];
}

int main()
{

  int t;
  cin >> t;
  while(t--)
  {
    int m,n;
    cin >> m >> n;
    string str1,str2;
    do{
        getline(cin,str1);
    }while(str1.size()==0);
    do{
        getline(cin,str2);
    }while(str2.size()==0);

    cout << longest_subsequence(str1,str2) << endl;
    
  }
  return 0;
}





