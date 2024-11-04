#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

	FILE *f;

	if(argc < 2){
		printf("Usage: errno_show file_name\n");
		exit(1);
	}

	if((f=fopen(argv[1], "r"))==NULL){
		printf("Cannot open a file "%s"... (errno: %d)\n", argv[1], arrno);
		exit(1);
	}

	printf("Open a file "%s". n", argv[1]);
	fclose(f);
}
