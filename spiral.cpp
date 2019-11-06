# include <iostream>

void print(int arr[],int n)
{

int i;
for (i = 0; i < n; i++)
	printf("%d ", arr[i]);
}

int main()
{

  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
  int n = sizeof(arr)/sizeof(arr[0]);
  print(arr,n);
  return 0;
}
