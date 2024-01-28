#include <stdio.h>
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <unistd.h>
//#include <sys.wait.h>

#define MAX_INPUT_LENGTH 2048
#define WORD_LIMIT 128

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

        }


    


}
