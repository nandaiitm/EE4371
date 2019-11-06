# include <iostream>
using namespace std;
int factorial(int);
int main()
{
    int t;
    while(t--)
    {
        int n;
        long long int k,count=1,sum=0;
        cin >> n;
        int data[n];
        for(int i=0;i<n;i++)
        {
            cin >> data[i];
        }
        cin >> k;
        while(count<=k)
        {
            for(int j=0;j<n;j++)
            {
                if(count%data[j]==0)
                {
                    sum++;
                    break;
                }
                else
                {
                    continue;
                }
                
            }
            count++;
        }
        cout << sum << endl;
    }
    return 0;
}
