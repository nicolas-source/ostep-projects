#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//whoops this actually dynamically reads a file.
int contains(char *haystack, char *needle);

int main(int argc, char *argv[]) {
//    printf("Int: %lu \n", sizeof(int));
//    printf("Char: %lu \n", sizeof(char));

    FILE *filePointer;
    filePointer = fopen(argv[1], "r");



//    size_t maxLineSize = 10;
//    char *line = malloc(maxLineSize * sizeof(char));
//
//    fgets(line, maxLineSize, filePointer);
//    printf("1 Line: %s", line);
//    printf("\nNum: %d", line[strlen(line) - 1]);
//
//    fseek(filePointer, -9, SEEK_CUR);
//
//
//    maxLineSize = maxLineSize * 2;
//    line = realloc(line, maxLineSize);
//    fgets(line, maxLineSize, filePointer);
//    printf("\n2 Line: %s", line);
//    printf("\nNum: %d", line[strlen(line) - 1]);
//
//    maxLineSize = 10;
//    fgets(line, maxLineSize, filePointer);
//    printf("\n3 Line: %s", line);
//    printf("\nNum: %d", line[strlen(line) - 1]);
//
//    fseek(filePointer, -9, SEEK_CUR);
//
//    maxLineSize = maxLineSize * 2;
//    line = realloc(line, maxLineSize);
//
//    fgets(line, maxLineSize, filePointer);
//    printf("\n4 Line: %s", line);
//    printf("\nNum: %d", line[strlen(line) - 1]);
//    printf("\n%s", fgets(line, maxLineSize, filePointer));


    size_t maxLineSize = 10;
    char *line = malloc(maxLineSize * sizeof(char));

//     outer loop: Iterates while not end of file
//     inner loop: Grabs next chunk of text while not end of line
    while (fgets(line, maxLineSize, filePointer) != NULL) {
//        printf("\n%s", line);
        // Resets maxLineSize
//        maxLineSize = 10;
        if (feof(filePointer)){
            printf("\nTrue: %s", line);

            break;
        }
        while (line[strlen(line) - 1] != '\n') {

            fseek(filePointer, -maxLineSize + 1, SEEK_CUR);

            maxLineSize = 2 * maxLineSize * sizeof(char);
            line = realloc(line, maxLineSize);

            if (fgets(line, maxLineSize, filePointer) == NULL) {
//                maxLineSize = 10;
                break;
            }
            printf("\nTrue: %s", line);
        }

    }

    fclose(filePointer);
    return (0);
}

int contains(char *haystack, char *needle){
       if (strstr(haystack, needle) != NULL) {
           return 1;
       } else {
           return 0;
       }
}