#include <stdio.h>
#include <unistd.h>

int main()
{
    int i = 0;
    printf("sabka baap process id : %d \n", getpid());
    printf("baap ka baap process id : %d \n", getppid());
    for (i=0; i<2; i++)
    {
        fork();
        printf("i : %d, ppid : %d, pid : %d\n", i, getppid(), getpid());
    }

    return 0;
}