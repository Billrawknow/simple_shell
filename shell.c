#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

int main() {
    char command[MAX_COMMAND_LENGTH];

    while (1) {
        printf("#cisfun$ "); // Display prompt
        fflush(stdout); // Flush the output buffer

        if (fgets(command, sizeof(command), stdin) == NULL) {
            // Handle end of file (Ctrl+D)
            printf("\nExiting the shell...\n");
            break;
        }

        // Remove the newline character
        command[strcspn(command, "\n")] = '\0';

        pid_t pid = fork();
        if (pid == 0) {
            // Child process
            if (execlp(command, command, NULL) == -1) {
                // If exec fails, print an error message
                perror("Command not found");
                exit(EXIT_FAILURE);
            }
        } else if (pid > 0) {
            // Parent process
            int status;
            waitpid(pid, &status, 0); // Wait for the child process to finish
        } else {
            // Forking error
            perror("Fork error");
        }
    }

    return 0;
}
