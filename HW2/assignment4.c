#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
 
int main() 
{
    int ret = fork();
 
    if (ret < 0) {
        printf("fork failed\n");
        return 1;
    }
 
    if (ret == 0) {
        execl("/bin/grep", "grep", "успеха", "test.txt", (char *)NULL);
        
        printf("execl failed\n");
        return 1;
    }
    
    waitpid(ret, NULL, 0);
    
    printf("Parent process completed\n");
    
    return 0;
}
