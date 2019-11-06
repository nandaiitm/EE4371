#include "stdio.h"
#include "stdlib.h"

int incid_mat[30][30]; //Stores the edges between nodes [Incidence Matrix]
int extra_turns[30]; //Stores the extra turns possible for a given color
int is_colored[30]; //Array to hold the colored status of a node
int color = 1; // initialise new color to be assigned
int n;
int vertice_color[30]; // hold the new color assignment for the vertice


/*
  Function to check if all vertices are colored or not
*/
int isAllColoured(){
    int flag = 1;
    for(int i = 0; i < n; i++){
        if(!is_colored[i]){
            flag = 0;
        }
    }
    return flag;
}

/*
  Function to check if a vertice is present in common_color or not
*/
int present_in_common_color(int common_color[n],int i){
    for(int p = 0; p < n; p++){
        if(common_color[p] == i){
            return 1;
            break;
        }
    }
    return 0;
}

/*
  Function to initialise the array of extra turns
*/
void initialize_extra(){
    for(int i = 0; i < n; i++){
        extra_turns[i] = 1;
    }
}

/*
  Function to initialise the array holding status of vertices
*/
void initialize_colored(){
    for(int i = 0; i <n; i++){
        is_colored[i] = 0;
    }
}

/*
  Implementation of greedy algorithm for coloring of nodes
*/
void greedy(){
    int found;
    int count = 0; // holds the count of the stack
    int common_color[n]; // Array containg the nodes having the same color
    /*
     initialising common_color
    */
    for(int i = 0; i < n; i++){
        common_color[i] = -1;
    }
    /*
     Iterate through all the vertices and check if it's not colored
    */
    for(int v = 0; v < n; v++){
        if(!is_colored[v]){
            found = 0;
            /*
             iterate thorugh incidence matrix and look for edge
            */
            for(int w = 0; w < count; w++){
                if(incid_mat[v][common_color[w]]){
                    found = 1;
                }
            }
            /*
             if edge is not found, assign a color and mark  it in is_colored[] array
            */
            if(!found){
                is_colored[v] = 1;
                vertice_color[v] = color;
                common_color[count] = v;
                count++;
            }
        }
}
    /*
     finding all possible values for turns
    */
    for(int w = 0; w < count; w++){
        for(int v = 0; v < n; v++){
            if(incid_mat[common_color[w]][v]){
                extra_turns[v] = 0;
            }
        }
    }
    /*
      Extra Turns = Possible Turns - Colored Turns
    */
    for(int i = 0; i < n; i++){
        if(extra_turns[i]){
            if(present_in_common_color(common_color,i)){
                extra_turns[i] = 0;
            }
        }
    }
}



int main( int argc, char **argv )
{
  if(argc != 2){
      printf("Enter File Name \n");
      exit(1);
  }
  FILE *fp ; char s[80] ;
  s[0] = 'n';
  s[1] = 'n';
  fp = fopen ( argv[1], "r" ) ;
  if ( fp == NULL )
  {
    puts ( "Cannot open file" ) ;
    exit(-1) ;
  }
  /*
    Taking the number of nodes from first line and storing it in @param: n
  */
  fgets ( s, 79, fp );
  if(s[1] == 'n')
    n = s[0] - '0';
  else{
    int a = s[0] - '0';
    int b = s[1] - '0';
    n = a*10 + b;
  }
  printf("%d\n",n );
  char nodes_file[n][80], im[n][80],nodes[n][2];
  /*
    Storing the nodes in @param: nodes[][]
  */
  for(int i=0;i<n;i++){
    fgets ( nodes_file[i], 79, fp );
    nodes[i][0] = nodes_file[i][0];
    nodes[i][1] = nodes_file[i][1];
  }
  /*
    Populating the incidence matrix in @param: incid_mat[][]
  */
  for(int i=0;i<n;i++){
      fgets ( im[i], 79, fp );
      int c=0,d=0;
      while(d<n){
          incid_mat[i][d] = im[i][c] - '0';
          d++;
          c=c+2;
      }
  }
  /*
   initialising is_colored and extra_turns boolean arrays
   */
  initialize_colored();
  initialize_extra();
  printf("Color\tTurns\t\tExtras\n");
  /*
   Call greedy till all vertices are colored
  */
  while(!isAllColoured()){
      greedy();
      printf("%d\t",color);
      for(int i = 0; i < n; i++){
          if(vertice_color[i] == color){
              printf("%c%c ",nodes[i][0],nodes[i][1]);
          }
      }
      printf("\t\t");
      for(int i = 0; i < n; i++){
          if(extra_turns[i]){
            printf("%c%c ",nodes[i][0],nodes[i][1]);
          }
      }
      initialize_extra();
      printf("\n");
      color++; // incrementing color for new color code
  }


  fclose ( fp ) ;
}