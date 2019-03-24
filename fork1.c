#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int a = 10;
    if(fork()==0)
    {
        a = a + 5;
        printf("in child : %d, %p \n", a, &a);
    }
    else
    {
        a = a - 5;
        printf("In parent : %d, %p \n", a, &a);
    }
    return 0;
}