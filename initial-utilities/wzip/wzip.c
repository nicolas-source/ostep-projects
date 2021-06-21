#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//whoops this actually dynamically reads a file.
int contains(char *haystack, char *needle);

void countOccurences(char *str);

void stringCreator(char currentChar, int count, char *newStr);

int main(int argc, char *argv[]) {
//    printf("Int: %lu \n", sizeof(int));
//    printf("Char: %lu \n", sizeof(char));

    FILE *filePointer;
    filePointer = fopen(argv[1], "r");


    size_t maxLineSize = 10;
    char *line = malloc(maxLineSize * sizeof(char));

//     outer loop: Iterates while not end of file
//     inner loop: Grabs next chunk of text while not end of line
    while (fgets(line, maxLineSize, filePointer) != NULL) {
//        printf("\n%s", line);
        // Resets maxLineSize
//        maxLineSize = 10;
        if (feof(filePointer)) {
            printf("\nTrue: %s", line);
            countOccurences(line);
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

        }
//        printf("\nTrue: %s", line);
        countOccurences(line);

    }

    fclose(filePointer);
    return (0);
}

void countOccurences(char *str) {
//    printf("\n%s", str);
//    printf("\n%lu", strlen(str));
    char newStr[64] = "";
    char currentChar;
    char nextChar;
    int count = 1;
    for (int i = 0; i < strlen(str); i++) {
        currentChar = str[i];
        nextChar = str[i + 1];
//        printf("\n%c %c", currentChar, nextChar);
        if (currentChar == nextChar) {

            count++;
        } else if (i == strlen(str) - 1) {
            stringCreator(currentChar, count, newStr);
        } else {
            stringCreator(currentChar, count, newStr);
            count = 1; // Reset count
        }
    }
//    printf("\nString: %s", newStr);
    newStr[strlen(newStr)] = '\0';
    char *outStr = malloc(strlen(newStr) * sizeof(char));
    strcpy(outStr, newStr);
//    printf("\nprintf: %s\n", outStr);
//    char outStr1[4] = "123";
    fwrite(outStr, sizeof(char), strlen(outStr) * sizeof(char), stdout);
//    printf("%s", outStr);
//    printf("\n%b", outStr);
}

void stringCreator(char currentChar, int count, char *newStr){

    //            strncat(newStr, &currentChar, 1);
    char chCC[2] = {currentChar, '\0'};



//    char tmp = count + '0';
//            strncat(newStr, &tmp, 1);
//    char chT[2] = {tmp, '\0'};

    int num = floor (log10 (abs (count))) + 1;
    char *tmpCount = malloc(num * sizeof(char));
    sprintf(tmpCount, "%d", count);
    strcat(newStr, tmpCount);
    strcat(newStr, chCC);
}


int contains(char *haystack, char *needle) {
    if (strstr(haystack, needle) != NULL) {
        return 1;
    } else {
        return 0;
    }
}