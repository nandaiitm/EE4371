#include <stdio.h>
#include <stdlib.h>

int n;
int incidence_arr[30][30];// Stores the edges between vertices in an square matrix
int extra_turns[30]; // determines the extra turns for a particular color
int is_colored[30]; // Array to determine if a vertex in the graph is colored or not
int color = 1; // initialise new color to be assigned
int vertice_color[30]; // holds the new color assignment for the vertice



int isAllColoured() //  Function to check if all vertices are colored or not
{
    int flag = 1;
    for(int i = 0; i < n; i++){
        if(!is_colored[i]){
            flag = 0;
        }
    }
    return flag;
}

int present_in_common_color(int common_color[n],int i) // Function to check if a vertice is present in common_color or not
{
    for(int p = 0; p < n; p++){
        if(common_color[p] == i){
            return 1;
            break;
        }
    }
    return 0;
}


void initialize_extra() // Function to initialise the array of extra turns
{
    for(int i = 0; i < n; i++){
        extra_turns[i] = 1;
    }
}


void initialize_colored() // Function to initialise the array holding status of vertices
{
    for(int i = 0; i <n; i++){
        is_colored[i] = 0;
    }
}


void greedy() //Implementation of greedy algorithm for coloring of nodes
{
    int found;
    int count = 0; // holds the count of the stack
    int common_color[n]; // Array containg the nodes having the same color
    for(int i = 0; i < n; i++) // initialising common_color
    {
        common_color[i] = -1;
    }
    for(int v = 0; v < n; v++) // Iterate through all the vertices and check if it's not colored
    {
        if(!is_colored[v])
        {
            found = 0;
            for(int w = 0; w < count; w++) // iterate thorugh incidence matrix and look for edge
            {
                if(incidence_arr[v][common_color[w]])
                {
                    found = 1;
                }
            }
            if(!found) // if edge is not found, assign a color and mark  it in is_colored[] array
            {
                is_colored[v] = 1;
                vertice_color[v] = color;
                common_color[count] = v;
                count++;
            }
        }
}
    
    for(int w = 0; w < count; w++) // finding all possible values for turns
    {
        for(int v = 0; v < n; v++)
        {
            if(incidence_arr[common_color[w]][v])
            {
                extra_turns[v] = 0;
            }
        }
    }
    for(int i = 0; i < n; i++) // Extra Turns = Possible Turns - Colored Turns
    {
        if(extra_turns[i]){
            if(present_in_common_color(common_color,i))
            {
                extra_turns[i] = 0;
            }
        }
    }
}



int main(int argc, char **argv)
{
  if(argc != 2)
  {
      printf("Please run the program in ./program <filename.dat> format\n");
      exit(1);
  }
  FILE *fp ;
  char s[120] ;
  s[0] = 'n';
  s[1] = 'n';
  fp = fopen ( argv[1], "r" ) ;
  if ( fp == NULL )
  {
    puts ( "Unable to open file" ) ;
    exit(1) ;
  }

  fgets ( s, 119, fp ); // Taking the number of nodes from first line and storing it in s
  n=atoi(s);  // converts character array into int
  printf("%d\n",n );
  char all_nodes[n][120], im[n][120],nodes[n][2];

  for(int i=0;i<n;i++) // Stores the nodes in nodes[][]
  {
    fgets ( all_nodes[i], 119, fp );
    nodes[i][0] = all_nodes[i][0];
    nodes[i][1] = all_nodes[i][1];
  }
  for(int i=0;i<n;i++) // Inputting the incidence matrix in incidence_arr[][]
  {
      fgets ( im[i], 119, fp );
      int c=0,d=0;
      while(d<n){
          incidence_arr[i][d] = im[i][c] - '0';
          d++;
          c=c+2;
      }
  }
  initialize_colored(); //initiales is_colored and extra_turns boolean arrays
  initialize_extra();
  printf("Color\tTurns\t\t\tExtra Turns\n");
  printf("------------------------------------------------\n");
  while(!isAllColoured()) // Executes until all vertices are colored
  {
      greedy();
      printf("%d\t",color);
      for(int i = 0; i < n; i++){
          if(vertice_color[i] == color){
              printf("%c%c,",nodes[i][0],nodes[i][1]);
          }
      }
      printf("\t\t\t");
      
      for(int i = 0; i < n; i++){
          if(extra_turns[i]){
            printf("%c%c,",nodes[i][0],nodes[i][1]);
          }
      }
      initialize_extra();
      printf("\n");
      color++; // incrementing color for new color code
  }


  fclose ( fp ) ;
}