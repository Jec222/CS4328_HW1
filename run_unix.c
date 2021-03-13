#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
     char *perent[]={"./pre",NULL};
     char *child[]={"./sort",NULL}; 
     char * const ls[] = {"ls", (char *)0};

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
        //  // child
        printf("child pid :%d \n",getpid());
        printf("parent pid :%d \n",getppid());

        printf("%s",argv[1]);
        if (strcmp (argv[1],"ls") == 0)
        {
            argv[2] = NULL;
            execv("/bin/ls", ls);
        }
    }
    else
    {
        if (pid != 0) // wait for child process to terminate 
            wait(NULL);
        //parent
    }
}  