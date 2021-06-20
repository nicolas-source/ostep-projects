#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int errno;

int main(int argc, char *argv[]) {

//    printf("argc = %d\n", argc);
//    printf("argv = %s\n", argv[0]);
//    printf("argv = %s\n", argv[1]);
//    printf("argv = %s\n", argv[2]);


    // char chunk[128];

    if (argv[1] == NULL) {
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }

    int errnum;
    FILE *filePointer = fopen(argv[2], "r");
    if (filePointer == NULL) {
        errnum = errno;
//          fprintf(stderr, "Value of errno: %d\n", errno);
//          perror("Error printed by perror");
//          fprintf(stderr, "Error opening file: %s\n", strerror( errnum ));
        if (errnum == 2) {
            printf("wgrep: cannot open file\n");
            exit(1);
        }
        char *buffer;
        size_t bufsize = 128;
        buffer = (char *) malloc(bufsize * sizeof(char));

        while (getline(&buffer, &bufsize, stdin) != -1){
            if (strstr(buffer, argv[1]) != NULL) {
                printf("%s", buffer);
            }
        }

        exit(0);
    }


    char *buffer;
    size_t bufsize = 128;
    buffer = (char *) malloc(bufsize * sizeof(char));

    size_t line = 0;

    while (line != -1) {
        line = getline(&buffer, &bufsize, filePointer);
        if (line == -1) {
            break;
        }
        if (strstr(buffer, argv[1]) != NULL) {
//            printf("line: %d\n", (int) line);
//            printf("line: %zu\n", line);
//            printf("buffer: %s\n", buffer);
            printf("%s", buffer);
        }

//        printf("substring: %s\n", strstr(buffer, argv[2]));
    }

    return 0;
}

