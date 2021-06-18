#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

//	char fileName[50] = argv[0];

    char *fileName = argv[1];
    
	printf("fileName = %s\n", fileName);
	printf("argc = %d\n", argc);
	printf("argv = %s\n", argv[1]);

	FILE *filePointer = fopen(fileName, "r");

	if (filePointer == NULL){
		printf("cannot open file\n");
		exit(1);
	}

    
    
    

    int length = 50;
    char str[length];
	if (fgets(str, length, filePointer) != NULL){
		puts(str);
	}
	fclose(filePointer);

	return(0);
}
