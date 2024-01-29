#include <stdio.h>
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 2048
#define WORD_LIMIT 128

char *words[WORD_LIMIT];


int main() {


    while(1) {
        printf("MUSH>");

        char input[MAX_INPUT_LENGTH];
        if(fgets(input, sizeof(input), stdin) == NULL) {
            perror("Error: cannot read input");
            exit(EXIT_FAILURE);
        }

        input[strcspn(input, "/n")] = '\0';

        char *words[WORD_LIMIT];
        char *token = strtok(input, " ");
        int wordCount = 0;

        while (token != NULL && wordCount < WORD_LIMIT - 1) {
            words[wordCount++] = token;
            token = strtok(NULL, " ");
        }

        words[wordCount] = NULL;  

        execvp(words[0], words);
        exit(1);

        //makeChild();


        if(strcmp(words[0], "cd") == 0) {
            chdir(words[1]);

            if(strcmp(chdir(words[1], -1)) == 0) {
                perror("Error: cannot change directory");
            }
        }   

        if(words[0] == "exit") {
            exit(0);
        }

    }

}


void makeChild() {
    
    pid_t pid = fork();

    if(pid == -1) {
        perror("Could Not Fork");
        exit(1);

    } else if (pid == 0) {
        execvp(words[0], words);
        exit(1);
    } else {
        wait(NULL);
    }
    
}