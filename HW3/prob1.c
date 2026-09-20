#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

	int ret1 = fork();

	if(ret1<0){
		perror("fork");
		return 1;
	}

	if(ret1 == 0){
		printf("child pid: %d\n", getpid());
		exit(0);

	} 
	else {
		printf("parent pid: %d\n", getpid());

	}

	return 0;

}
