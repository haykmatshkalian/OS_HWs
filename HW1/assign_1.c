#include <stdio.h>

int main(){

    int a = 10;
    int *addr_a = &a;

    printf("Address of a using var is %p\n", &a);
    printf("Address of a using pointer is %p\n", addr_a);

    *addr_a = *addr_a + 5;

    printf("New val of a is %d\n", a);

    return 0;
}
