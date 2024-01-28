#include <stdio.h>
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <unistd.h>
//#include <sys.wait.h>

#define MAX_INPUT_LENGTH 2048
#define MAX_WORDS 128

int main() {


    while(1) {
        printf("MUSH>");

        char input[MAX_INPUT_LENGTH];
        if(fgets(input, sizeof(input), stdin) == NULL) {
            perror("Error: cannot read input");
            exit(EXIT_FAILURE);
        }



        }


    


}