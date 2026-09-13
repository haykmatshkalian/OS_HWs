#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
int main() 
{ 
	
        int ret1 = fork();
	if(ret1 < 0){
		printf("first fork failed");
		return 1;
	}
	
	int ret2 = fork();
	if(ret2 < 0) {
		printf("second fork failed");
		return 1;
	}

        int ret3 = fork();
	if(ret3 < 0){
		printf("third fork failed");
		return 1;
	}
        while(1);

	return 0;
}
