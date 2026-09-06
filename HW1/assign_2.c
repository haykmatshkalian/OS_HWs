#include <stdio.h>

int main() {

    int arr[] = {5, 10, 15, 20, 25};

    int *addr_arr = arr;

    printf("Original array:\n");

    for (int i = 0; i < 5; i++) {
        printf("%d ", *(addr_arr + i));
    }

    printf("\n");

    for (int i = 0; i < 5; i++) {
        *(addr_arr + i) = *(addr_arr + i) * 2;
    }

    printf("Modified array using pointer:\n");

    for (int i = 0; i < 5; i++) {
        printf("%d ", *(addr_arr + i));
    }

    printf("\n");

    printf("Modified array using array name:\n");

    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}