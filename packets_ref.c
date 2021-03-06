/*
    Name : Akshit Kumar
    Roll No. : EE14B127
    Question : Implement a FIFO queue using circular queues to insert packets as they are inserted and run a simulation to dequeue packets.
*/

// Including the necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

// Defining the maximum queue size
#define MAX_QUEUE_SIZE 10000

// Defination of the PACKET struct which holds all the relevant details about the packet
typedef struct PACKET{
    int type; // if HTTP packet, type = 0 else type == 1
    double t_arrival; // contains the arrival time of the packet in seconds
    int size; // if HTTP packet, size = 80 else size = 400
}PACKET;

// Instantiating an array of structure PACKET to hold all the packets read from the input file ie midterm-input.dat
PACKET packets[MAX_QUEUE_SIZE];
int file_size = 0; // Initialising the file size to 0

/*
    Function to generate a new packet
    @param type : type of the packet
    @param t_arrival : arrival time of the packet 
    @param size : size of the packet
*/
PACKET generate_packet(int type, double t_arrival, int size){
    PACKET packet;
    packet.type = type;
    packet.t_arrival = t_arrival;
    packet.size = size;
    return packet;
}

/*
    Function to read the entire file and store all the packets in an array - packets
    @param argv : Get the file name to read the packets from
*/
void read_packets_from_input_file(char** argv){
    FILE *file = fopen(argv[1],"r"); // open the file specified in command line input
    if(file == NULL){
        printf("Unable to open file\n");
        exit(1);
    }
    char line[128]; // assign a string to read a line from the file
    int i = 0;
    int type,size;
    double t_arrival;
    // read the file til end of file is reached
    while(fgets(line,sizeof line,file) != NULL){
        bool isTime = true;
        // Remove the '\n' character from end of each line
        char *pos;
        if ((pos=strchr(line,'\n')) != NULL)
            *pos = '\0';
        // tokenize the string read by a space
        char *token;
        token = strtok(line," "); // returns a pointer to a list containing words separated by a space
        // iterate till the pointer points to NULL
        while (token != NULL) {
            if(isTime){
                sscanf(token,"%lf",&t_arrival); // read in the arrival time of the packet
            }
            else{
                if(strcmp(token,"http") == 0){
                    type = 0; // set the type of the packet
                    size = 80; // set the size of the packet
                }
                else if(strcmp(token,"video") == 0){
                    type = 1; // set the type of the packet
                    size = 400; // set the size of the packet
                }
            }
            isTime = false;
            token = strtok(NULL," "); // make the pointer point to next word
        }
        PACKET packet = generate_packet(type,t_arrival,size); // generate an instant of the structure
        packets[i++] = packet; // insert that packet into the packets array
        file_size++; // increase the file size by 1 with every line that is read
    }
    fclose(file); // close the file after reading it completely
}

// Instantiating the queue of size 10000
PACKET queue[MAX_QUEUE_SIZE];
// Assigning the helper variables for the queue
int front = -1;
int rear = -1;

/*
    Helper functions for implementation of a circular queue
    queue_full()
    queue_empty()
    enqueue_packet(PACKET packet)
    dequeue_packet()
*/

// Checks if the queue is full or not
bool queue_full(){
    if((front == rear + 1) || (front == 0 && rear == MAX_QUEUE_SIZE - 1)){
        return true;
    }
    return false;
}

// Check if the queue is empty of not
bool queue_empty(){
    if(front == -1){
        return true;
    }
    return false;
}

// Function to enqueue a packet into the queue
void enqueue_packet(PACKET packet){
    if(queue_full())
        printf("Queue overflow\n");
    else{
        if(rear == -1){
            rear = 0;
            front = 0;
        }
        else if(rear == MAX_QUEUE_SIZE - 1)
            rear = 0;
        else
            rear++;
        queue[rear] = packet;
    }
}

// Function to dequeue a packet from the queue
PACKET dequeue_packet(){
    PACKET packet;
    if(queue_empty())
        printf("Queue underflow\n");
    else{
        packet = queue[front];
        if(front == rear){
            front = -1;
            rear = -1;
        }
        else if(front == MAX_QUEUE_SIZE - 1)
            front = 0;
        else
            front++;
    }
    return packet;
}

// initialising variables for keeping track of time in the simulation
double current_time = 0.000000; // holds the current time in the simulation
double t_next_enqueue; // time required to enqueue the next packet into the queue
double t_next_dequeue; // time required to dequeue the next packet from the queue
int count_http_drop = 0, count_video_drop = 0; // hold the count of http and video packet drops
int count_http_inserted = 0, count_video_inserted = 0; // hold the count of http and video packets inserted
bool is_dropped = false; // hold if the packet is being dropped or not
int i = 0;

// arrays to hold the summary of each second
int http_inserted[16]; 
int video_inserted[16];
int http_sent[16];
int video_sent[16];
int http_dropped[16];
int video_dropped[16];

PACKET packet; 
FILE *output_file;

// Function to drop stale packets
void drop_stale_packets(){
    do{
        // Pick the packet at the front of the queue
        PACKET packet = queue[front]; 
        is_dropped = false;
        // if the packet is of type http
        // check if the packet is old by 15 seconds or not
        // if it is, update is_dropped to true and drop the packet
        // find the time for dequeueing the next packet
        if(packet.type == 0){
            if(fabs(current_time - packet.t_arrival) > 15.000000){
                is_dropped = true;
                packet = dequeue_packet();
                count_http_drop++;
                fprintf(output_file,"%lf\t%s\t%s\n",current_time,"http","DROP");
                http_dropped[(int)current_time]++;
                t_next_dequeue = ((double)queue[front].size)/64000.0;
            }
        }
        // if the packet is of type video
        // check if the packet is old by 1 seconds or not
        // if it is, update is_dropped to true and drop the packet
        // find the time for dequeueing the next packet
        else{
            if(fabs(current_time - packet.t_arrival) > 1.000000){
                is_dropped = true;
                packet = dequeue_packet();
                count_video_drop++;
                fprintf(output_file,"%lf\t%s\t%s\n",current_time,"video","DROP");
                video_dropped[(int)current_time]++;
                t_next_dequeue = ((double)queue[front].size)/64000.0;
            }
        }
        // continue dequeueing the packets while the queue doesn't get empty or packet can be dropped
    }while(is_dropped && !queue_empty());
}

// Function to send the packets
void send_packet(){
    // increment the current time by the time required to dequeue the packet
    current_time += t_next_dequeue;
    packet = dequeue_packet(); // dequeue the packet
    if(packet.type == 0){
        fprintf(output_file,"%lf\t%s\t%s\n",current_time,"http","SENT");
        http_sent[(int)current_time]++;
    }
    else{
        fprintf(output_file,"%lf\t%s\t%s\n",current_time,"video","SENT");
        video_sent[(int)current_time]++;
    }
    // decrement the time required to enqueue the packets by time required to dequeue the packet
    t_next_enqueue -= t_next_dequeue;
    // if the queue is not empty, update the time for the next packet to be dequeued
    if(!queue_empty()){
        t_next_dequeue = ((double)queue[front].size)/64000.0;
    }
}

// Function to receive the packets
void receive_packet(){
    // increment the current time by the time required to enqueue the packet
    current_time += t_next_enqueue;
    // decrease the time required to dequeue by subtracting the time required to enqueue the packet
    t_next_dequeue -= t_next_enqueue;
    if(packets[i].type == 0){
        enqueue_packet(packets[i]);
        count_http_inserted++;
        http_inserted[(int) current_time]++;
    }
    else{
        enqueue_packet(packets[i]);
        count_video_inserted++;
        video_inserted[(int) current_time]++;
    }
    // calculate the time for enqueueing the next packet
    t_next_enqueue = packets[++i].t_arrival;
    // get the time for enqueueing the next packet
    t_next_enqueue -= current_time;
}

int main(int argc, char** argv){
    if(argc != 2){
        printf("Usage ./a.out <filename>\n");
        exit(1);
    }
    FILE *summary_file;
    summary_file = fopen("summary-1.dat","w");
    output_file = fopen("output-1.dat","w");
    fprintf(output_file,"%s\t\t%s\t%s\n","time","type","action");
    read_packets_from_input_file(argv);
    t_next_enqueue = packets[i].t_arrival;
    // iterate through the entire file
    while (i <= file_size) {
        // if the queue is not empty, then receive a packet
        // set time for dequeueing the next packet
        if(queue_empty()){
            receive_packet();
            t_next_dequeue = ((double)queue[front].size)/64000.0;
        }
        // drop the stale packets
        drop_stale_packets();
        // if the time to dequeue the next packet is less than time to enqueue, then dequeue
        if(t_next_dequeue < t_next_enqueue && !queue_empty()){
            send_packet();
        }
        // if the time to dequeue the next packet is more than the time required to enqueue the next packet
        else if(t_next_enqueue <= t_next_dequeue){
            receive_packet();
        }
    }
    fclose(output_file);
    // printing out the necessary details 
    printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\n","Time","HTTP Q","Video Q","HTTP Sent","Video Sent","HTTP Drop","Video Drop");
    fprintf(summary_file, "%s\t%s\t%s\t%s\t%s\t%s\t%s\n","Time","HTTP Q","Video Q","HTTP Sent","Video Sent","HTTP Drop","Video Drop");
    for(int i = 0; i < 16; i++){
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\t\t%d\n",i,http_inserted[i]*80,video_inserted[i]*400,http_sent[i]*80,video_sent[i]*400,http_dropped[i]*80,video_dropped[i]*400);
        fprintf(summary_file,"%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i,http_inserted[i]*80,video_inserted[i]*400,http_sent[i]*80,video_sent[i]*400,http_dropped[i]*80,video_dropped[i]*400);
    }
    printf("Summary of Packet Drops :\n");
    fprintf(summary_file, "Summary of Packet Drops :\n");
    printf("%s : %f \n","% HTTP Packet Drop ", (float)count_http_drop/(float)count_http_inserted * 100.0);
    fprintf(summary_file, "%s : %f \n","% HTTP Packet Drop ", (float)count_http_drop/(float)count_http_inserted * 100.0);
    printf("%s : %f \n","% Video Packet Drop ", (float)count_video_drop/(float)count_video_inserted * 100.0);
    fprintf(summary_file, "%s : %f \n","% Video Packet Drop ", (float)count_video_drop/(float)count_video_inserted * 100.0);
    return 0;
}