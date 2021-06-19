#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){

	printf("argc = %d\n", argc);
        printf("argv = %s\n", argv[0]);
	printf("argv = %s\n", argv[1]);
	printf("argv = %s\n", argv[2]);

	FILE *filePointer = fopen(argv[1], "r");

	// char chunk[128];

	char *buffer;
	size_t bufsize = 32;
	buffer = (char *)malloc(bufsize * sizeof(char));

    size_t line = 0;

    while (line != -1){
        line = getline(&buffer, &bufsize, filePointer);
        if (line == -1){
            break;
        }
        if (strstr(buffer, argv[2]) != NULL){
            printf("line: %d\n", (int)line);
            printf("line: %zu\n", line);
            printf("buffer: %s\n", buffer);
        }

//        printf("substring: %s\n", strstr(buffer, argv[2]));
    }

	return 0;
}

