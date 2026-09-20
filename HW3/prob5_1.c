#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int pid;

    pid = fork();

    if(pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if(pid == 0) {
        
        printf("Child process: PID = %d\n", getpid());
        exit(0);
    }
    else {
        
        printf("Parent process: PID = %d\n", getpid());
        printf("Parent is sleeping...\n");

        sleep(30);
    }

    return 0;
}
