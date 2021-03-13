#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10
#define STATE_FORMAT 20
#define MAX_POPULATION 10

int main(void)
{
    char state[MAX_SIZE][STATE_FORMAT];
    char temp[STATE_FORMAT];

    int j = 0;
    int k = 0;
    int _actual_size = 0;

//    printf("Enter State\n");

     while(!feof(stdin) && k < MAX_SIZE)
     {
         scanf("%s",state[k]);
         k++;
         _actual_size++;
     }

    for (k = 0; k < _actual_size-1; k++)
    {
        for(j = k+1; j < _actual_size-1; j++)
        {
            if(strcmp(state[k],state[j]) > 0)
            {
                strcpy(temp,state[k]);
                strcpy(state[k],state[j]);
                strcpy(state[j],temp);   
            }
        }
    }

//    printf("The ouputs ahould be:\n");

    for(k = 0; k < _actual_size-1; k++)
    {
        //printf("%i\n",k);
        printf("%s\n",state[k]);
        //puts(state[k]);
    }
      

    return 0;
}

