#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int found_e = 0;
int found_dot = 0;
int found_minus = 0;
int found_plus = 0;
int found_multiply = 0;
int found_divide = 0;
int found_num = 0;

struct node
{
double val;
struct node *next;
};
struct node *head;

void initialise(){
  found_e = 0;
  found_dot = 0;
  found_minus = 0;
  found_plus = 0;
  found_multiply = 0;
  found_divide = 0;
  found_num = 0;
}

void validate_1(char cc,char c[]){
  if(cc=='0' || cc=='1' || cc=='2' || cc=='3' || cc=='4' || cc=='5' || cc=='6' || cc=='7' || cc=='8' || cc=='9'){
    found_num = found_num + 1;
  }

  if(cc == 'e'){
    found_e = found_e + 1;
  }

  if(cc == '.'){
    if(found_e != 0) {
      printf("Invalid expr. Illegal tag: %s\n", c);
      exit(-1);
    }
    found_dot = found_dot + 1;
  }

  if(cc == '+'){
    if(found_dot != 0) {
      printf("Invalid expr. Illegal tag: %s\n", c);
      exit(-1);
    }
    if(found_num != 0) {
      printf("Invalid expr. Illegal tag: %s\n", c);
      exit(-1);
    }
    found_plus = found_plus + 1;

  }

  if(cc == '-'){
    if(found_dot != 0) {
      printf("Invalid expr. Illegal tag: %s\n", c);
      exit(-1);
    }
    if(found_num != 0) {
      printf("Invalid expr. Illegal tag: %s\n", c);
      exit(-1);
    }
    found_minus = found_minus + 1;
  }

  if(cc == '*'){
    if(found_dot != 0) {
      printf("Invalid expr. Illegal tag: %s\n", c);
      exit(-1);
    }
    if(found_num != 0) {
      printf("Invalid expr. Illegal tag: %s\n", c);
      exit(-1);
    }
    if(found_e != 0) {
      printf("Invalid expr. Illegal tag: %s\n", c);
      exit(-1);
    }
    found_multiply = found_multiply + 1;
  }

  if(cc == '/'){
    if(found_dot != 0) {
      printf("Invalid expr. Illegal tag: %s\n", c);
      exit(-1);
    }
    if(found_num != 0) {
      printf("Invalid expr. Illegal tag: %s\n", c);
      exit(-1);
    }
    if(found_e != 0) {
      printf("Invalid expr. Illegal tag: %s\n", c);
      exit(-1);
    }
    found_divide = found_divide + 1;
  }
}

void validate_2(char c[]){
  if(found_e>1) {
    printf("Invalid expr. Multiple e present. %s\n", c);
    exit(-1);
  }

  if(found_dot>1) {
    printf("Invalid expr. Multiple . present. %s\n", c);
    exit(-1);
  }

  if(found_multiply>1) {
    printf("Invalid expr. Multiple * present. %s\n", c);
    exit(-1);
  }

  if(found_minus>1)
  {
    printf("Invalid expr. Multiple - present. %s\n", c);
    exit(-1);
  }

  if(found_plus>1) {
    printf("Invalid expr. Multiple + present. %s\n", c);
    exit(-1);
  }

  if(found_divide>1) {
    printf("Invalid expr. Multiple / present. %s\n", c);
    exit(-1);
  }
}

void push (float val)
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL)
    {
        printf("not able to push the element");
        exit(0);
    }
    else
    {
        if(head==NULL)
        {
            ptr->val = val;
            ptr -> next = NULL;
            head=ptr;
        }
        else
        {
            ptr->val = val;
            ptr->next = head;
            head=ptr;

        }

    }
}

float pop()
{
    double item;
    struct node *ptr;
    if (head == NULL)
    {
        printf("Underflow");
        exit(0);
    }
    else
    {
        item = head->val;
        ptr = head;
        head = head->next;
        free(ptr);
        return item;

    }
}

int main(int argc, const char * argv[]) {
    char ch[1000];
    char c[1000];
    char * cptr;
    int i = 0;
    // top = -1;
    FILE *fptr;
    /*
      File name of Test File should be Postfix_test.txt
    */
    if ((fptr = fopen("Postfix_test.txt", "r")) == NULL)
    {
        printf("Error! opening file");
        /*
          Program exits if file pointer returns NULL.
        */
        exit(1);
    }
    fgets(ch,100,fptr);
    puts(ch);
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
        for (temp=c; *temp; temp++) {
          char cc = *temp;
          validate_1(cc,c);
        }

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
    printf("%f \n",pop());
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time spent in Array implementation %f\n",time_spent);
    // display();
    fclose(fptr);
    return 0;
}
	
