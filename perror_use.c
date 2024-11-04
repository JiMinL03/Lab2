#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]){
	FILE *f;

	if(argc < 2){
		 printf("Usage: strerror_use nofilename\n");
                exit(1);
	}

	if((f=fopen(argv[1], "r"))==NULL){
		perror("fopen");
		exit(1);
	}

	printf("Opened file \"%s\".\n", argv[1]);
    fclose(f);
}
