#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

#define TOTAL_CLOCK_TIME 100000

struct PACKET{
int id; // packet id
int t0; // arrival time of packet
};

struct PACKET *create_packet(int num, int arrival_time)
{
    struct PACKET *p;
    p=(struct PACKET *)malloc(sizeof(PACKET));
    p->id = num;
    p->t0 = arrival_time;
    return p;
}

struct queue 
{ 
    int rear, front;  
    int capacity; 
    struct PACKET *arr;    //doubt
};

struct queue *create_queue(int size)
{
    struct queue *q=(struct queue*)malloc(sizeof(struct queue));
    if(!q)
    {
        printf("Memory limit Exceeded\n");
        return NULL; 
    }
    q->capacity=size;
    q->front=q->rear=-1;
    q->arr=(struct PACKET*)malloc(q->capacity*sizeof(struct PACKET)); 
}

int isempty(struct queue *q)
{
    return q->front == -1; 
}

int isfull(struct queue *q)
{
    return ((q->rear+1) % q->capacity == q->front);
}

int queuesize(struct queue *q)
{
    return (q->rear - q->front + 1 + q->capacity)%q->capacity;
}

void enQueue(struct queue *q, PACKET p) 
{ 
    if (isfull(q)) 
    { 
        printf("Queue is Full\n"); 
        return; 
    } 
    else
    { 
        q->rear=(q->rear+1)%q->capacity;
        q->arr[q->rear]=p;
        if(q->front==-1)
        {
            q->front=q->rear;
        }
    }   
} 
  
int deQueue(struct queue *q) 
{ 
    int time;
    if (isempty(q)) 
    { 
        // printf("Queue is Empty\n"); 
        return 0; 
    } 
    else
    {
        time=(q->arr[q->front]).t0;
        if(q->front==q->rear)
        {
            q->front = -1;
            q->rear = -1;
        }
        else
        {
            q->front = (q->front+1) % q->capacity;
        }  
    }
    
    return time; 
} 

int nextTime(float rateParameter){
return (int)(-logf(1.0f - (float) rand() / (RAND_MAX + 1.0)) / rateParameter);
}


int main()
{
    int n=20;
    float ratePar=0.45,mu=0.5;

    struct queue *node_queue=create_queue(n);

    int total_intervals=(int)(1.0*TOTAL_CLOCK_TIME*ratePar);

    int clock_time=0, count_interval=1, it=0, sum=0, dropped_count=0, service_count=0;
    
    while(count_interval<=total_intervals)
    {   

        while(clock_time<(int)(count_interval/ratePar))
        {   
            
            if(!isfull(node_queue))
            {
                clock_time=clock_time+nextTime(ratePar);
                struct PACKET *p=create_packet(it+1,clock_time);
                
                enQueue(node_queue,*p);
                service_count++;
                it++;
                
            }
            else
            {
                clock_time=clock_time+nextTime(ratePar);
                dropped_count++;
            }  
        }
        
        for(int i=0;i<(int)(mu/ratePar);i++)
        {
            int packet_stored_time=deQueue(node_queue);
            sum = sum + (int)(count_interval/ratePar) - packet_stored_time;
        }
        count_interval=count_interval+1;
    }

    cout << "The average time per packet is " << (int)(sum/(total_intervals*(mu/ratePar))) << endl;

    cout << "The percentage of Dropped packets is " << (float)dropped_count/(dropped_count+service_count) << endl;

    
    return 0;
}