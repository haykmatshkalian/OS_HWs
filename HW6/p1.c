#include <stdio.h>

int main() {
    	int num = 10;
    	char ch = 'A';
    	double value = 3.14;
    	short small = 5;

    	printf("Size of int: %zu bytes\n", sizeof(num));
    	printf("Size of char: %zu bytes\n", sizeof(ch));
    	printf("Size of double: %zu bytes\n", sizeof(value));
	printf("Size of short: %zu bytes\n", sizeof(small));

    	printf("\nAddresses of variables:\n");
    	printf("int:    %p\n", (void *)&num);
    	printf("char:   %p\n", (void *)&ch);
    	printf("double: %p\n", (void *)&value);
    	printf("short:  %p\n", (void *)&small);

    	return 0;
}
