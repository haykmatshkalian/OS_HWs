#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	printf("Enter the number of elements: ");

	if (scanf("%d", &n) != 1) {
		return 1;
	}

        if(n<=0) return 1;

	int *numbers = calloc(n, sizeof(int));

	if(numbers == NULL) return 1;

	printf("Array after calloc: ");

	for(int i =0; i<n; i++){
		printf("%d ", numbers[i]);
	}

        printf("\nEnter %d integers:  ", n);

	for(int i = 0; i<n; i++){
		if (scanf("%d", &numbers[i]) != 1) {
			free(numbers);
			return 1;
		}
	}

        printf("Updated array: ");

        for(int i =0; i<n; i++){
                printf("%d ", numbers[i]);
        }

	double avg = 0;

	for(int i =0; i<n; i++){
		avg = avg + numbers[i];

	}

	avg = avg/n;

	printf("\nAverage of the array: %f\n",  avg);

	free(numbers);
	return 0;
}
