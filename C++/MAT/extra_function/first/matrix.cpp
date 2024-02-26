#include "matrix.h"

int main() {
    int rows, cols;
    int **matrix;

    std::cout << "请输入矩阵A的行数和列数" << endl;
    std::cin >> rows >> cols;
    std::cout << "请输入矩阵A" << endl;
    matrix = (int **)malloc(sizeof(int *) * rows);
    for(int i = 0;i < rows;i++){
        matrix[i] = (int *)malloc(sizeof(int) * cols);
    }
    for(int i = 0;i < rows;i++){
        for(int j = 0;j < cols;j++){
            std::cin >> matrix[i][j];
        }
    }
    Matrix A(rows, cols, matrix);

    std::cout << "请输入矩阵B的行数和列数" << endl;
    std::cin >> rows >> cols;
    std::cout << "请输入矩阵B" << endl;
    matrix = (int **)malloc(sizeof(int *) * rows);
    for(int i = 0;i < rows;i++){
        matrix[i] = (int *)malloc(sizeof(int) * cols);
    }
    for(int i = 0;i < rows;i++){
        for(int j = 0;j < cols;j++){
            std::cin >> matrix[i][j];
        }
    }
    Matrix B(rows, cols, matrix);

    std::cout << "A + B = " << endl;
    std::cout << A + B;

    std::cout << "A - B = " << endl;
    std::cout << A - B;

    std::cout << "A * B = " << endl;
    std::cout << A * B;

    bool flag = A == B;
    std::cout << "A == B = " << endl;
    if(flag == 0) std::cout << "false" << endl;
    else std::cout << "true" << endl;

    std::cout << "经拷贝构造函数矩阵A得到的矩阵C" << endl;
    Matrix C = A;
    std ::cout << C;

    std::cout << "经重载运算符 = 重新得到的矩阵B" << endl;
    B = A;
    std ::cout << B;
    return 0;
}