# include <iostream>
# include <vector>
using namespace std;
void equaliser(int* arr,int size,int diff,int sis);
int main()
{
    int t;
    while(t--)
    {
        int n,mila;
        cin >> n >> mila;
        int gila=0;
        vector<int> data(n);
        for (int i = 0; i < n; i++)
        {
            cin >> data[i];
            gila+=data[i];
        }
        int diff=gila-mila;
        if(diff<0)
        {
            cout << 0 << endl;
        }
        else if(diff%2==1)
        {
            cout << 0 << endl;
        }
        else
        {
            equaliser(data,n,diff,mila);
        }
        

        
    }
    return 0;
}
void equaliser(int* arr,int size,int diff,int sis)
{
    cout << 0 << endl;
}
