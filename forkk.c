#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
int main()
{
    pid_t pid, p, w;
    //create child process
    int i = 0;
    for (i; i < 5; i++)
    {
        pid = fork();
        if (pid == 0)
            break;
        else
        {
            if (i == 0)
                p = pid;
        }
    }
    if (pid < 0)
    {
        perror("fork error.\n");
        exit(0);
    }
    else if (pid == 0)
    {
        if (i == 0)
        { //child1
            sleep(5);
        }
        printf("child%d process,pid = %d\n", i, getpid());
    }
    else
    {
        w = waitpid(p, NULL, 0);
        if (w == p)
            printf("Catch a child process:pid=%d\n", w);
        else
            printf("waitpid error\n");
    }
    return 0;
}
