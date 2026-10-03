#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	printf("Enter the number of elements: ");

	if (scanf("%d", &n) != 1) {
		return 1;
	}

        if(n<=0) return 1;

	int *numbers = malloc(n * sizeof(int));


	if(numbers == NULL) return 1;

        printf("Enter %d integers:  ", n);

	for(int i = 0; i<n; i++){
		if (scanf("%d", &numbers[i]) != 1) {
			free(numbers);
			return 1;
		}
	}

	int sum = 0;
	for(int i =0; i<n; i++){
		sum = sum + numbers[i];

	}

	printf("Sum of the array: %d\n", sum);

	free(numbers);

	return 0;
}
