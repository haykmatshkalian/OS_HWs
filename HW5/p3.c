#include <stdio.h>
#include <stdlib.h>

int main(){
	int *numbers = malloc(10*sizeof(int));
	if(numbers == NULL) return 1;

	printf("Enter 10 integers: ");

	for(int i = 0; i<10; i++){
		if (scanf("%d", &numbers[i]) != 1) {
			free(numbers);
			return 1;
		}
	}


	int *tmp = realloc(numbers, 5*sizeof(int));

	if(tmp == NULL){
		free(numbers);
		return 1;
	}

	printf("Array after resizing: ");
	for(int i =0; i<5; i++){
		printf("%d ", tmp[i]);
	}
	printf("\n");

	free(tmp);



	return 0;
}
