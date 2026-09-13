#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    int ret1 = fork();

    if (ret1 < 0) return 1;

    if (ret1 == 0) {
        execl("/bin/ls", "ls", (char *)NULL);

        perror("execl ls failed");
        return 1;
    }
    else {
	waitpid(ret1, NULL, 0);

        int ret2 = fork();

        if (ret2 < 0) {
            perror("fork failed");
            return 1;
        }

        if (ret2 == 0) {
            execl("/bin/date", "date", (char *)NULL);

            perror("execl date failed");
            return 1;
        }
        else {
            waitpid(ret2, NULL, 0);

            printf("Parent process done\n");
        }
    }

    return 0;
}
