#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int pid;

    pid = fork();


    if(pid < 0) {
        perror("fork failed");
        exit(1);
    }

    if(pid == 0) {

        printf("child process pid = %d\n", getpid());
        exit(0);
    }
     
    else {

        printf("parent process pid = %d\n", getpid());
        printf("parent is waiting for child \n");


        wait(NULL);

        printf("child has finished\n");
    }

    return 0;
}
