#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

	int ret1 = fork();

	if(ret1<0){
		perror("fork");
		return 1;
	}

	if(ret1 == 0){
		printf("child1 pid: %d\n", getpid());
		sleep(2);
		printf("child1 finished\n");

		exit(10);

	} 

	int ret2 =fork();

	if(ret2<0){
		perror("fork failed");
		exit(1);
	}

	if(ret2==0){
		printf("child2 pid: %d\n", getpid());
		sleep(4);
		printf("child2 finished\n");
		exit(11);
	}

	
		printf("parent pid: %d\n", getpid());
		printf("parent waiting for child2\n");

		int status;
		waitpid(ret2, &status, 0);

		printf("parent process: child2 has finished \n");
		printf("child2 exit status: %d\n", WEXITSTATUS(status));
	
		wait(&status);

	        printf("parent process: child 1 has finished\n");
        	printf("child 1 exit status: %d\n", WEXITSTATUS(status));

	return 0;

}
