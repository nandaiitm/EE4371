# include <iostream>
# include <algorithm>
# include <vector>
# include <cmath>
# include <string>
// # include <bits/stdc++.h>
using namespace std;

string rotate(string s,int i,char mini)
{
    string rot_str,useless;
    for(int j=i;j<s.size();j++)
    {
        rot_str.push_back(s[j]);
    }
    for(int m=0;m<i;m++)
    {
        useless.push_back(s[m]);
    }
    while(mini!=rot_str[0])
    {
        string dummy=rot_str;
        for(int k=0;k<rot_str.size();k++)
        {
            dummy[k]=rot_str[(k+1)%rot_str.size()];
        }
        rot_str=dummy;
    }
    return (useless+rot_str);

}

int main()
{
    string s,temp;
    int flag=0,count=0;
    do{
        getline(cin,s);
    }while(s.size()==0);
    temp=s;
    for(int i=0;i<s.size();i++)
    {
        int mini=s[i];
        for(int j=i;j<s.size();j++)
        {
            if(s[j]<mini)
            {
                mini=s[j];
                flag=1;
            }
            else
            {
                continue;
            }
            
        }
        if(mini!=s[i])
        {

            temp=rotate(s,i,mini);
            
        }
        if(flag==1)
        {
            count++;
            
        }
        flag=0;
        s=temp;
    }
    cout << count << endl;
    
  
    return 0;
}





