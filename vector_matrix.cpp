#include <iostream>
#include <vector>

int main() {
    int rows, cols;
    std::cout << "행렬의 행과 열의 크기를 입력하세요 (예: 2 3): ";
    std::cin >> rows >> cols;

    std::vector<std::vector<int>> matrixA(rows, std::vector<int>(cols));
    std::vector<std::vector<int>> matrixB(rows, std::vector<int>(cols));
    std::vector<std::vector<int>> result(rows, std::vector<int>(cols));

    std::cout << "첫 번째 행렬의 내용을 입력하세요:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << "matrixA[" << i << "][" << j << "]: ";
            std::cin >> matrixA[i][j]; 
        }
    }

    std::cout << "두 번째 행렬의 내용을 입력하세요:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << "matrixB[" << i << "][" << j << "]: ";
            std::cin >> matrixB[i][j];  
            result[i][j] = matrixA[i][j] + matrixB[i][j];  
        }
    }

    std::cout << "두 행렬의 합:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << result[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}

