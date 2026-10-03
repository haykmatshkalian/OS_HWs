#include <stdio.h>
#include <stdlib.h>


int main(){
	int n;
	printf("Enter the number of students: ");
	if (scanf("%d", &n) != 1) {
		return 1;
	}

	if(n<=0){return 0;}

	int *grades = malloc(n*sizeof(int));

	if(grades == NULL){return 1;}

        printf("Enter the grades:  ");

	for(int i = 0; i<n; i++){
		if (scanf("%d", &grades[i]) != 1) {
			free(grades);
			return 1;
		}
	}

	int high = grades[0];
	int low = grades[0];
	for(int i =0; i<n; i++){
		if(grades[i] < low) low = grades[i];
		if(grades[i] > high) high = grades[i];

	}


	printf("Highest grade: %d\n", high);
	printf("Lowest grade: %d\n", low);


	free(grades);

	return 0;

}
