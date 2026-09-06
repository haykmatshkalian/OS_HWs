#include <stdio.h>

int main(){
    char str[] = "Hello";
    char *ptr = str;
    int i = 0;

    printf("String using pointer: ");
    while (*(ptr + i) != '\0') {
        printf("%c ", *(ptr + i));
        i++;
    }   

    printf("\n");

    printf("Number of characters: %d\n", i);

    return 0;
}
