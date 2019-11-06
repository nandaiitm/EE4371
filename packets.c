	
#include <math.h>
#include <stdlib.h>
#include "stdio.h"
#include "time.h"

// Defining the maximum queue size
#define MAX_QUEUE_SIZE 10000
int N, del_t;
float lamb_da, mu;
typedef struct{
int id; // packet id
int t0; // arrival time of packet
int t1;//exit time of packet
} PACKET;

PACKET generatePacket(int id, int t0){
  PACKET packet;
  packet.t0 = t0;
  packet.t1 = 0;
  packet.id = id;
  return packet;
}

PACKET packets[MAX_QUEUE_SIZE];

int nextTime(float rateParameter)
{
  return (int)(-log(1.0f - (float) rand() / (RAND_MAX + 1.0)) / rateParameter) ;
}

int main(){
  float rateParameter = 0.45;
  // p = (PACKET *)malloc(sizeof(PACKET));
  for(int i=0;i<MAX_QUEUE_SIZE;i++){
    packets[i] = generatePacket(i+1,nextTime(rateParameter));
  }

  N=5;
  lamb_da = 0.45;
  mu = 0.5;
  del_t = 1.0/lamb_da;
  int time = 0;
  // total_packets is the number of packets remaining in queue
  int c=0, total_packets=0, dropped_packets=0;
  while(c<MAX_QUEUE_SIZE){
    total_packets = total_packets + 1;
    time = time + packets[c].t0;

    if(time>del_t){
      total_packets = total_packets -1;
      if(total_packets > N){
        dropped_packets = dropped_packets + (total_packets - N);
        total_packets = N;
      }
      // del_t time has passed. So the total number of packets in the queue will decrease by mu*time
      int packets_dec = (int)(mu * del_t);
      if(packets_dec > total_packets ) 
        total_packets = 0;
      else
        total_packets = total_packets - packets_dec;
      time = time-del_t;
      total_packets = total_packets + 1;

    }
    else if(time==del_t){
      if(total_packets > N){
        dropped_packets = dropped_packets + (total_packets - N);
        total_packets = N;
      }
      // del_t time has passed. So the total number of packets in the queue will decrease by mu*time
      int packets_dec = (int)(mu * del_t);
      if(packets_dec > total_packets ) total_packets = 0;
      else total_packets = total_packets - packets_dec;
      time = time-del_t;
    }
    c=c+1;
  }
  printf("%d\n",dropped_packets);



  return 1;
}
	
	
	
