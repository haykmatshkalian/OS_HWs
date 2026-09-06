#include <stdio.h>

int main(){
    int a = 10;
    int *ptr_a = &a;
    int **ptr_ptr_a = &ptr_a;
   
    printf("Value of a using pointer: %d\n", *ptr_a);
    printf("Value of a using double-pointer: %d\n", **ptr_ptr_a);

    return 0;
}
