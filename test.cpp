# include <iostream>
using namespace std;
void test(int*,int,int);
int min_index(int*,int,int);
int main()
{
	int arr[]={0,2,3,4,7,6,5,1};
	int size=sizeof(arr)/sizeof(int);
	test(arr,0,size-1);
	cout << arr[0] << endl;


	for(int i=0;i<size;i++)
	{
		cout << arr[i] << " ";
	}


	return 0;
}
void test(int a[],int start_ind,int end_ind)
{
	if(start_ind>=end_ind)
		return;
	int min_ind,temp;
	min_ind=min_index(a,start_ind,end_ind);
	temp=a[start_ind];
	a[start_ind]=a[min_ind];
	a[min_ind]=temp;
	test(a,start_ind+1,end_ind);
}
int min_index(int arra[],int start_ind,int end_ind)
{
	int i=start_ind,min=arra[start_ind],index=start_ind;
	for(i;i<=end_ind;i++)
	{
		if(arra[i]<min)
		{
			min=arra[i];
			index=i;
		}

		else
			continue;
		return index;
	}
}
