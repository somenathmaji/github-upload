// demonstration of fork() and pipe()
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>

int main()
{   
    int fd1[2];
    int fd2[2];

    char fixed_char[] = ", I love you <3";
    
    
    if(pipe(fd1)==-1)
    {
        fprintf(stderr, "pipe failed \n");
        return 1;
    }
    if(pipe(fd2)==-1)
    {
        fprintf(stderr, "pipe failed \n");
        return 1;
    }
    
    pid_t p;
    p = fork();
    if(p<0)
    {
        fprintf(stderr, "fork failed\n");
        return 1;
    }
    else if(p>0)
    {
        // get the string, we want to concat with some fixed string
        char input_str[100];
        printf("input string -\n");
         scanf("%s", input_str);
        // close the read end and write to the write end, finally close the write end as well 
        close(fd1[0]);
        write(fd1[1], input_str, strlen(input_str)+1);
        close(fd1[1]);
        // wait for the chile process do it's stuff and signal the parent
        wait(NULL);
        // get the result and print on the screen
        char concat_str[100];
        close(fd2[1]);
        read(fd2[0], concat_str, 100);
        close(fd2[0]);
        printf("concat string is -\n%s\n", concat_str);
    }
    else
    {
        // close the write end and read the input string
        close(fd1[1]);
        char result_str[100];
        read(fd1[0], result_str, 100);
        close(fd1[0]);
        // concat the fixed string to the input string
        int k = strlen(result_str);
        for(int i=0; i<strlen(fixed_char); i++)
            result_str[k++] = fixed_char[i];
        result_str[k] = '\0';
        // write the result into the pipe
        close(fd2[0]);
        write(fd2[1], result_str, strlen(result_str)+1);
        close(fd2[1]);
        // signal it's done
        exit(0);
    }
    
}