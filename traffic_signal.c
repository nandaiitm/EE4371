#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    // char file_name[25];
    // FILE *f;

    // printf("Enter name of a file you wish to see\n");
    // gets(file_name);
    // f = fopen(file_name, "r"); // read mode

    // if (f == NULL)
    // {
    //   printf("Error while opening the file.\n");
    //   exit(-1);
    // }

    // printf("The contents of %s file are:\n", file_name);

    // char n_nodes[5];
    // fgets(n_nodes,3,f);
    // int n=(int)(*n_nodes);
    // char arr[6][3];
    // char ch,ch1,ch2;
    // ch=fgetc(f);
    // ch1=fgetc(f);

    // for(int i=0;i<ch;i++)
    // {
    //     for(int j=0;j<3;j++)
    //     {
    //         arr[i][j]=fgetc(f);
    //     }

    // }
    // printf("%c",arr[0][1]);

    int n=6;
    char arr[6][2]={"AB","AC","AD","BA","BC","BD"};
    int matrix[6][6]={0,0,0,0,0,0,
                    0,0,0,1,0,1,
                    0,0,0,1,0,0,
                    0,1,1,0,0,0,
                    0,0,0,0,0,0,
                    0,1,0,0,0,0};

    int coloured[n];
    for(int m=0;m<n;m++)
    {
        coloured[m]=0;
    }
    int all_coloured=0;
    int colour_num=0;
    while(all_coloured!=1)
    {
        int node_list[n];
        for(int m=0;m<n;m++)
        {
            node_list[m]=0;
        }
        int count1=0;
        for(int i=0;i<n;i++)
        {
            int found=0;
            if(coloured[i]==0)
            {
                if(count1==0)
                {
                    node_list[i]=1;
                    coloured[i]=1;
                }
                count1++;
                for(int j=0;j<n;j++)
                {
                    if(node_list[j]==1)
                    {
                        if(matrix[i][j]==1)
                            {
                                found=1;
                            }
                    }
                }
                if(found==0)
                {
                    coloured[i]=1;
                    node_list[i]=1;
                }
            }
        }
        printf("colour %d\n",colour_num);
        for(int p=0;p<n;p++)
        {
            if(node_list[p]==1)
            {
                printf("%c%c ",arr[p][0],arr[p][1]);
            }

        }
        printf("\n");
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(coloured[i]==0)
            {
                count++;
            }
        }
        if(count==0)
        {
            all_coloured=1;
        }
        colour_num++;

    }


    return 0;
}