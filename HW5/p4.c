#include <stdio.h>
#include <stdlib.h>

int main(){

	char **strings = malloc(3 * sizeof(char *));

	if(strings == NULL) return 1;

	for (int i = 0; i < 3; i++) {
		strings[i] = malloc(51 * sizeof(char));
		if(strings[i] == NULL){
			for (int j = 0; j < i; j++) {
            			free(strings[j]);
        		}
			free(strings);
			return 1;
		}
	}

	printf("Enter 3 strings: ");

	for(int i = 0; i<3; i++){
		if (scanf("%50s", strings[i]) != 1) {
        		for (int j = 0; j < 3; j++) {
            			free(strings[j]);
        		}
			free(strings);
			return 1;
		}
	}

	printf("Printing saved strings: ");
	for(int i=0; i<3; i++){
		printf("%s ", strings[i]);
	}
	printf("\n");

	char **tmp = realloc(strings, 5* sizeof(char *));

	if(tmp ==NULL){
		for (int i = 0; i < 3; i++) {
        		free(strings[i]);
  		}
		free(strings);
		return 1;
	}

	strings = tmp;

        for (int i = 3; i < 5; i++) {
                strings[i] = malloc(51 * sizeof(char));
                if(strings[i] == NULL){
                        for (int j = 0; j < i; j++) {
            			free(strings[j]);
        		}

			free(strings);
                        return 1;
                }
        }

        printf("Enter 2 more strings: ");

        for(int i = 3; i<5; i++){
                if (scanf("%50s", strings[i]) != 1) {
                        for (int j = 0; j < 5; j++) {
            			free(strings[j]);
        		}

			free(strings);
                        return 1;
                }
        }

	printf("All strings: ");
        for(int i=0; i<5; i++){ 
                printf("%s ", strings[i]);
        }
	        printf("\n");

	for (int i = 0; i < 5; i++) {
    		free(strings[i]);
	}

	free(strings);

	return 0;
}
