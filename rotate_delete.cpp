#include <iostream>
#include <vector>
using namespace std;
void rotate(vector<int> data);
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> data(n);
        for(int i=0;i<n;i++)
        {
            cin >> data[i];
        }
        int k=n-1,count=1;

        while(count<=k)
        {
            rotate(data);
            if(data.size()-count+1>=data.size())
            {
               data.erase(data.begin()+data.size()-count); 
            }
            else
            {
                data.erase(data.begin(),data.begin());
            }
            
            count++;
        }
    }
}
void rotate(vector<int> data)
{
    
}