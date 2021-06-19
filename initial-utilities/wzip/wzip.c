#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
//    printf("Int: %lu \n", sizeof(int));
//    printf("Char: %lu \n", sizeof(char));

    FILE *filePointer;
//    char c;
//    char megaChar[] = "\0";
//
//    //---Reading
    filePointer = fopen(argv[1], "r");
//    while(1){
//        c = fgetc(filePointer);
//        if (feof(filePointer)){
//            break;
//        }
//        strncat(megaChar, &c, 1);
//        printf("%c ", c);
//    }
//    fclose(filePointer);
//
//    printf("%s", megaChar);




    size_t maxLineSize = 10;
    char *line = malloc(maxLineSize * sizeof(char));

    while(fgets(line, maxLineSize, filePointer)){
        // while not yet read complete line
        while(line[strlen(line)-1] != '\n' && line[strlen(line) - 1] != '\r'){
            printf("%s\n", line);
            line = realloc(line, 2 * sizeof(line));
            printf("%s\n", line);
            fseek(filePointer, strlen(line)-1, SEEK_CUR);
            printf("%s\n", line);
            fgets(line, maxLineSize, filePointer);
        }
    }
//    fgets(line, maxLineSize, filePointer);
    printf("%d\n", fgets(line, maxLineSize, filePointer)[9]);
    printf("%d\n", line[9]);
    printf("%s%lu\n", line, strlen(line));
    printf("%s\n", fgets(line, maxLineSize, filePointer));
    printf("%s\n", line);
    printf("%d\n", 'a');
    //---Writing
//    char str[] = "aaabbb";
//
//    filePointer = fopen("file.z", "w");
//    fwrite(str, 1, sizeof(str), filePointer);
//
//    fclose(filePointer);

    return(0);
}
