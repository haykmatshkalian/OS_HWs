#include <stdio.h>
#include <stdlib.h>

void function1() {
    printf("Function 1 called.\n");
}

void function2() {
    printf("Function 2 called.\n");
}

int main() {
    atexit(function1);
    atexit(function2);

    printf("Main function is running.\n");

    // exit(0); // If exit() is called here, code after it will not execute,
                // but the atexit() functions will still be called.

    printf("Main function continues.\n");

    exit(0);

    // Observation:
    // When exit() is reached, the program terminates.
    // The registered atexit() functions run before the program finishes.
    // They execute in reverse order of registration: function2, then function1.

    return 0;
}
