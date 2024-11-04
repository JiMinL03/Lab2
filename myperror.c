#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void my_perror(const char *s) {
    if (s) {
        printf("%s: ", s);
    }
    printf("%s\n", strerror(errno));
}

int main(int argc, char *argv[]) {
    FILE *f;
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    if ((f = fopen(argv[1], "r")) == NULL) {
        my_perror(argv[1]);
        exit(1);
    }
    printf("Opened file \"%s\".\n", argv[1]);
    fclose(f);
    return 0;
}

