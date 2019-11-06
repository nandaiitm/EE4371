#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int found_tag_e = 0;
int found_tag_dot = 0;
int found_tag_minus = 0;
int found_tag_plus = 0;
int found_tag_multiply = 0;
int found_tag_divide = 0;
int found_tag_num = 0;
double stack[20];
int top;
/*
  Initialising the variables keeping count of all the allowed characters
*/
void initialise(){
  found_tag_e = 0;
  found_tag_dot = 0;
  found_tag_minus = 0;
  found_tag_plus = 0;
  found_tag_multiply = 0;
  found_tag_divide = 0;
  found_tag_num = 0;
}

/*
  Validation Part 1
*/
void validate_1(char cc,char c[]){
  if(cc=='0' || cc=='1' || cc=='2' || cc=='3' || cc=='4' || cc=='5' || cc=='6' || cc=='7' || cc=='8' || cc=='9'){
    found_tag_num = found_tag_num + 1;
  }

  if(cc == 'e'){
    found_tag_e = found_tag_e + 1;
  }

  if(cc == '.'){
    if(found_tag_e != 0) {
      printf("Invalid expr. Illegal tag: %s\n", c);
      exit(-1);
    }
    found_tag_dot = found_tag_dot + 1;
  }

  if(cc == '+'){
    if(found_tag_dot != 0) {
      printf("Invalid expr. Illegal tag: %s\n", c);
      exit(-1);
    }
    if(found_tag_num != 0) {
      printf("Invalid expr. Illegal tag: %s\n", c);
      exit(-1);
    }
    found_tag_plus = found_tag_plus + 1;

  }

  if(cc == '-'){
    if(found_tag_dot != 0) {
      printf("Invalid expr. Illegal tag: %s\n", c);
      exit(-1);
    }
    if(found_tag_num != 0) {
      printf("Invalid expr. Illegal tag: %s\n", c);
      exit(-1);
    }
    found_tag_minus = found_tag_minus + 1;
  }

  if(cc == '*'){
    if(found_tag_dot != 0) {
      printf("Invalid expr. Illegal tag: %s\n", c);
      exit(-1);
    }
    if(found_tag_num != 0) {
      printf("Invalid expr. Illegal tag: %s\n", c);
      exit(-1);
    }
    if(found_tag_e != 0) {
      printf("Invalid expr. Illegal tag: %s\n", c);
      exit(-1);
    }
    found_tag_multiply = found_tag_multiply + 1;
  }

  if(cc == '/'){
    if(found_tag_dot != 0) {
      printf("Invalid expr. Illegal tag: %s\n", c);
      exit(-1);
    }
    if(found_tag_num != 0) {
      printf("Invalid expr. Illegal tag: %s\n", c);
      exit(-1);
    }
    if(found_tag_e != 0) {
      printf("Invalid expr. Illegal tag: %s\n", c);
      exit(-1);
    }
    found_tag_divide = found_tag_divide + 1;
  }
}

/*
  Validation Part 2
*/
void validate_2(char c[]){
  if(found_tag_e>1) {
    printf("Invalid expr. Multiple e present. %s\n", c);
    exit(-1);
  }

  if(found_tag_dot>1) {
    printf("Invalid expr. Multiple . present. %s\n", c);
    exit(-1);
  }

  if(found_tag_multiply>1) {
    printf("Invalid expr. Multiple * present. %s\n", c);
    exit(-1);
  }

  if(found_tag_minus>1)
  {
    printf("Invalid expr. Multiple - present. %s\n", c);
    exit(-1);
  }

  if(found_tag_plus>1) {
    printf("Invalid expr. Multiple + present. %s\n", c);
    exit(-1);
  }

  if(found_tag_divide>1) {
    printf("Invalid expr. Multiple / present. %s\n", c);
    exit(-1);
  }
}

/*
  Push to stack
*/
void push(float c)
{
    if(top>=19)
    {
        printf("\n\tSTACK is over flow");

    }
    else
    {
        top++;
        stack[top]=c;
    }
}

/*
  Pop from stack
*/
float pop()
{
    if(top<=-1)
    {
        printf("\n\t Stack is under flow");
        exit(0);

    }
    else
    {
        top = top-1;
        return stack[top+1];
    }
}

/*
  Display stack
*/
void display()
{
    if(top>=0)
    {
        printf("\n The elements in STACK \n");
        for(int i=top; i>=0; i--)
            printf("\n%f",stack[i]);
    }
    else
    {
        printf("\n The STACK is empty");
    }

}

/*
  Main function which can take file name input from command line
*/
int main(int argc, const char ** argv) {
    char ch[1000];
    char c[1000];
    char * cptr;
    int i = 0;

    FILE *fptr;
    /*
      File name of Test File should be Postfix_test.txt
    */
    fptr = fopen(argv[1], "r");
    if (fptr == NULL)
    {
        printf("Error! opening file");
        /*
          Program exits if file pointer returns NULL.
        */
        exit(1);
    }
    int cun=0;
      top = -1;

    fgets(ch,100,fptr);
    printf("----------------------------------------------------------------------" );
    printf("\nPostfix Expression:\t" );
    puts(ch);
    // printf("----------------------------------------------------------------------\n" );
    /*
        Tokenize the Postfix Expression into individual tokens delimited by space and tab
    */
    cptr = strtok(ch," \t");
    clock_t begin = clock();
    while(cptr!= NULL)
    {   strcpy(c, cptr);
        char * temp;
        initialise(); //Initialising the validating variables for each token
        /*
            Iterating over the individual characters of the token and validating it
        */

        validate_2(c); // Validating

        /*
            Checking for Operator
        */
        if((strcmp(c,"+"))==0 || (strcmp(c,"-"))==0 || (strcmp(c,"*"))==0 || (strcmp(c,"/"))==0)
        {
            i = i-1;
            double s1,s2;
            /*
              Check if the operator has sufficient operands to operate on
            */
            if(i<1)
            {   printf("Stack doesn't have enough numerics to continue operation");
                exit(1);
            }
            /* Compute the subexpression for an operator and store it back in stack
            */
            else if(strcmp(c,"+") == 0){
              s1= pop();
              s2=pop();
              push(s1+s2);
            }
            else if(strcmp(c,"-") == 0){
              s1= pop();
              s2=pop();
              push(s2-s1);
            }
            else if(strcmp(c,"*") == 0)
            {
              s1= pop();
              s2=pop();
              push(s1*s2);
            }
            else if(strcmp(c,"/") == 0){
              s1= pop();
              s2=pop();
              push(s2/s1);
            }
        }
        else
        {
            /*
              Converting character to float and pushing it to stack
            */
            push(atof(c));
            i = i+1;
        }

        cptr = strtok(NULL,"\t");
    }
    printf("Answer:\t %f \n",pop());
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time spent in Array implementation of stack:\t%f seconds\n",time_spent);
    printf("----------------------------------------------------------------------\n" );

    fclose(fptr); //clearing memory buffer
    return 0;
}