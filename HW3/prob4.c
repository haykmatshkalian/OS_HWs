#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int pid1, pid2;
    int status;

    pid1 = fork();

    if (pid1 < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid1 == 0) {
        printf("Child 1: PID = %d\n", getpid());
        exit(5);
    }

    pid2 = fork();

    if (pid2 < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid2 == 0) {
        printf("Child 2: PID = %d\n", getpid());
        exit(10);
    }

    printf("Parent process: PID = %d\n", getpid());

    waitpid(pid1, &status, 0);

    if (WIFEXITED(status)) {
        printf("Child 1 exited normally with status: %d\n",
               WEXITSTATUS(status));
    } else {
        printf("Child 1 exited with an error.\n");
    }

    waitpid(pid2, &status, 0);

    if (WIFEXITED(status)) {
        printf("Child 2 exited normally with status: %d\n",
               WEXITSTATUS(status));
    } else {
        printf("Child 2 exited with an error.\n");
    }

    return 0;
}
