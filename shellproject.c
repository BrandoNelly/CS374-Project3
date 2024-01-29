#include <stdio.h>
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 2048
#define WORD_LIMIT 128

char *words[WORD_LIMIT];
int wordCount = 0;


void makeChild(char* words[]) {
    
    pid_t pid = fork();

    if(pid == -1) {
        perror("Could Not Fork");
        exit(EXIT_FAILURE);

    } else if (pid == 0) {
        if(execvp(words[0], words) == -1) {
        exit(EXIT_FAILURE);
        }

    } else {
        wait(NULL);
    } 
}


int main() {


    while(1) {
        printf("MUSH>");

        char input[MAX_INPUT_LENGTH];
        if(fgets(input, sizeof(input), stdin) == NULL) {
            perror("Error: cannot read input");
            exit(EXIT_FAILURE);
        }

        input[strcspn(input, "\n")] = '\0';

        char *token = strtok(input, " ");

        while (token != NULL && wordCount < WORD_LIMIT - 1) {
            words[wordCount++] = token;
            token = strtok(NULL, " ");
        }


        if(strcmp(words[0], "cd") == 0) {
            if(chdir(words[1]) == -1) {
                perror("Error: cannot change directory");
            }
        }   

        if(strcmp(words[0], "exit") == 0) {
            exit(0);
        }

        words[wordCount] = NULL;  
        makeChild(words);
        wordCount = 0;

    }

}

