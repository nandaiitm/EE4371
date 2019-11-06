#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <string.h> /* memset */
#include <unistd.h> /* close */

#define countOfN 10000
int N;
int recur_count;

void generateRandoms(int lower, int upper, int count, int arr[])
{
    int i;
    for (i = 0; i < count; i++) {
        arr[i] = (rand() % (upper - lower + 1)) + lower;

    }
}

bool knapsack(int W,int i, int w[]){
    recur_count = recur_count + 1;
    if (W==0)
        return true;
    else if (W<0 || i>=N)
        return false;
    else if (knapsack(W-w[i],i+1,w)){
        return true;
    }
    else
        return knapsack(W,i+1,w);
}

int main(void) {
    /*
      Using current time as seed for random generator
    */
    srand(time(0));
    int Num[countOfN] = { 0 };
    /*
      Generate 10000 N between [1,20]
    */
    generateRandoms(1, 20, countOfN, Num);

    /*
      first column is min, second is max, third is average
    */
    int count_arr[20][3];
    for(int i=0;i<20;i++){
        count_arr[i][0] = INT_MAX;
        count_arr[i][1] = 0;
        count_arr[i][2] = 0;
    }


    int sum[20][2];
    for(int i=0;i<20;i++){
        sum[i][0] = 0;
        sum[i][1] = 0;
    }
    for(int i=0;i<countOfN;i++){
        /*
          N is defined here for each case
        */
        N = Num[i];
        /*
          Generate 1 W between [0,N*N/2]
        */
        int n = (N*N)/2;
        int Weight[] = { 0 };
        generateRandoms(0, n, 1, Weight);
        int W = Weight[0];
        /*
          Generate N w_i between [0,N]
        */
        int w[N];
        memset( w, 0, N*sizeof(int) );
        /*
          Generate N random number between [0,N] ==> w_i
        */
        generateRandoms(0, N, N , w);

        recur_count = 0;
        knapsack(W, 0, w);
        sum[N-1][0] = sum[N-1][0] + recur_count;
        sum[N-1][1] = sum[N-1][1] + 1;
        if(recur_count<count_arr[N-1][0])
            count_arr[N-1][0] = recur_count;
        if(recur_count>count_arr[N-1][1])
            count_arr[N-1][1] = recur_count;
    }
    float avg[20];

	  printf("N\tMin\tMax\tAverage\n");
    for(int i=0;i<20;i++){
      avg[i] = (1.0*sum[i][0])/sum[i][1] ;
        	printf("%d\t%d\t%d\t%f\n",i+1,count_arr[i][0],count_arr[i][1],avg[i]);
    }
	return 0;
}