#include <stdio.h>
#include <stdlib.h>
#include <mcheck.h>

#define MAX 20

int main() {
    // 메모리 추적 시작
    mtrace();

    int *ptr1 = (int*) malloc(MAX * sizeof(int));
    int *ptr2 = (int*) malloc(MAX * sizeof(int));

    if (ptr1 == NULL || ptr2 == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1; // 메모리 할당 실패 시 종료
    }

    for (int i = 0; i < MAX; i++) {
        ptr1[i] = i;
        ptr2[i] = MAX - i;
    }

    // 메모리 해제
    free(ptr1);
    free(ptr2);

    // 메모리 추적 종료
    muntrace();

    return 0;
}

