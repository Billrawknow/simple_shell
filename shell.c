#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024

int main(void) {
    char input[MAX_INPUT_SIZE];
    pid_t pid;
    
    while (1) {
        printf("#cisfun$ ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            perror("fgets");
            exit(EXIT_FAILURE);
        }
        
        /* Remove newline character from input */
        input[strcspn(input, "\n")] = '\0';
        
        if (strcmp(input, "exit") == 0) {
            printf("Exiting the shell...\n");
            break;
        }
        
        pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            /* Child process */
            execlp(input, input, NULL);
            perror("execlp");
            exit(EXIT_FAILURE);
        } else {
            /* Parent process */
            int status;
            waitpid(pid, &status, 0);
        }
    }
    
    return 0;
}
