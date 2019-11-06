#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>

#define COUNT_OF_N 10000
int N,rec_count; //rec_count tracks the number of times knapsack is called

//Generates random integers, using the rand() function, between given bounds and feeds it into array
void generate_random_nums(int lower_bound, int upper_bound, int count, int arr[]) 
{ 
    int i; 
    for (i = 0; i < count; i++) 
    { 
        arr[i] = (rand()%(upper_bound-lower_bound+1))+lower_bound;  
    } 
} 

bool knapsack(int W,int i, int w[])
{ 
    rec_count = rec_count + 1;
    if (W==0)
        return true;
    else if (W<0 || i>=N)
        return false;
    else if (knapsack(W-w[i],i+1,w))
    {
        return true;
    }
    else
        return knapsack(W,i+1,w);
}

int main(void) 
{
    srand(time(0)); // sets the seed which is used by rand to generate random numbers
    int random_nums[COUNT_OF_N] = { 0 };
    generate_random_nums(1, 20, COUNT_OF_N, random_nums); // generates 10000 integers between 1 & 20 and stores it inside array
    
    int count_arr[20][3]; // first column is min, second is max
    for(int i=0;i<20;i++)
    {
        count_arr[i][0] = INT_MAX;
        count_arr[i][1] = 0;
        count_arr[i][2] = 0;
    }
    int sum[20][2];
    for(int i=0;i<20;i++){
        sum[i][0] = 0;
        sum[i][1] = 0;
    }    
    for(int i=0;i<COUNT_OF_N;i++)
    {
        N = random_nums[i]; //N is initialized
        int n = (N*N)/2;
        int weight[] = { 0 };
        generate_random_nums(0, n, 1, weight); 
        int W = weight[0]; // Initializes W between 0 & N*N/2
        int w[N];
        memset( w, 0, N*sizeof(int) );
        generate_random_nums(0, N, N , w);  // Generates N random numbers between [0,N] and stores it in w
        rec_count = 0;
        knapsack(W, 0, w);
        sum[N-1][0] = sum[N-1][0] + rec_count;
        sum[N-1][1] = sum[N-1][1] + 1;
        if(rec_count<count_arr[N-1][0])
            count_arr[N-1][0] = rec_count;
        if(rec_count>count_arr[N-1][1])
            count_arr[N-1][1] = rec_count;
    }
    float avg[20];

	  printf("N     Min     Max     Average\n");
    for(int i=0;i<20;i++){
      avg[i] = (1.0*sum[i][0])/sum[i][1] ;
        	printf("%d      %d       %d      %f\n",i+1,count_arr[i][0],count_arr[i][1],avg[i]);
    }
	return 0;
}
	
	
	
