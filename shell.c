#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

int main() {
    char command[MAX_COMMAND_LENGTH];

    while (1) {
        printf("#cisfun$ ");
        fflush(stdout);

        if (fgets(command, sizeof(command), stdin) == NULL) {
            printf("\nExiting the shell...\n");
            break;
        }

        command[strcspn(command, "\n")] = '\0'; // Remove newline character

        if (strcmp(command, "exit") == 0) {
            printf("Exiting the shell...\n");
            break;
        }

        // Handle other commands here
        // ...
    }

    return 0;
}
