#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;

    // 행렬의 크기 입력
    printf("행렬의 행과 열의 크기를 입력하세요 (예: 2 3): ");
    scanf("%d %d", &rows, &cols);

    // 메모리 동적 할당
    int **matrixA = malloc(rows * sizeof(int *));
    int **matrixB = malloc(rows * sizeof(int *));
    int **result = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrixA[i] = malloc(cols * sizeof(int));
        matrixB[i] = malloc(cols * sizeof(int));
        result[i] = malloc(cols * sizeof(int));
    }

    // 첫 번째 행렬 입력
    printf("첫 번째 행렬의 내용을 입력하세요:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("matrixA[%d][%d]: ", i, j);
            scanf("%d", &matrixA[i][j]);  // 한 개씩 입력
        }
    }

    // 두 번째 행렬 입력 및 더하기
    printf("두 번째 행렬의 내용을 입력하세요:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("matrixB[%d][%d]: ", i, j);
            scanf("%d", &matrixB[i][j]);  // 한 개씩 입력
            result[i][j] = matrixA[i][j] + matrixB[i][j];  // 바로 더하기
        }
    }

    // 결과 출력
    printf("두 행렬의 합:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // 메모리 해제
    for (int i = 0; i < rows; i++) {
        free(matrixA[i]);
        free(matrixB[i]);
        free(result[i]);
    }
    free(matrixA);
    free(matrixB);
    free(result);

    return 0;
}

