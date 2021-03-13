#include <stdio.h>

#define MAX_SIZE 10
#define STATE_FORMAT 20
#define MAX_POPULATION 10

int main(void)
{
    int _population[MAX_SIZE][STATE_FORMAT] = {0};
    char state[MAX_SIZE][STATE_FORMAT];

    int k = 0;

//    printf("enter state and population size\n");

     while(!feof(stdin) && k < MAX_SIZE)
     {
         scanf("%s %d",state[k],_population[k]);
         k++;
     }
     k = 0;
     while(k < MAX_SIZE)
     {
         if (*_population[k]> MAX_POPULATION)
         {
              printf("%s\n", state[k]);
         }
         k++;
     }
    return 0;
}

