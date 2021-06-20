#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int errno;

int main(int argc, char *argv[]) {
    int errnum;

    int length = 50;
    char str[length];

    int i = 1;
    while (argv[i] != NULL) {
        FILE *filePointer = fopen(argv[i], "r");
        if (filePointer == NULL) {
            errnum = errno;
//          fprintf(stderr, "Value of errno: %d\n", errno);
//          perror("Error printed by perror");
//          fprintf(stderr, "Error opening file: %s\n", strerror( errnum ));
            if (errnum == 2) {
                printf("wcat: cannot open file\n");
                exit(1);
            }
            exit(0);
        }

        while (fgets(str, length, filePointer) != NULL) {
//		puts(str);
            printf("%s", str);
        }
        fclose(filePointer);
        i++;
    }


    return (0);
}
