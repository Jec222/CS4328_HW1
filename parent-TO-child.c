#include <stdio.h>
#include <unistd.h>
#include <unistd.h>

int main(void)
{
     char *perent[]={"./pre",NULL};
     char *child[]={"./sort",NULL}; 

    int fd[2]; // file description table
    int pid;

    pipe(fd); // create pipe 

    pid = fork();

    if (pid < 0) // error
    {
         printf("error\n");
    }
    else if (pid == 0)
    {
         // child inharetes pipe (same pipe)
         close(0);
         dup(fd[0]);
         close(fd[0]);
         close(fd[1]);
         execvp(child[0],child);
         //exec("more");
    }
    else
    {
         //parent
         close(1);
         dup(fd[1]);
         close(fd[1]);
         close(fd[0]);
         execvp(perent[0],perent);
    }
}