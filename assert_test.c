#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void foo(int num) {
    assert((num >= 0) && (num <= 100));
    printf("foo:num = %d\n", num);
}

int main(int argc, char *argv[]) {
    int num;
    if (argc < 2) {
        fprintf(stderr, "Usage: assert_test aNumber\n (0 <= aNumber <= 100)\n");
        exit(1);
    }

    num = atoi(argv[1]);
    foo(num);
    return 0; // main 함수의 정상 종료를 위해 return 추가
}

