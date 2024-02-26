#include "matrix.h"

int main() {
    int rows, cols;
    
    std::cout <<"请输入矩阵A的行和列" ;
    std::cin>> rows >> cols;
    Matrix A(rows, cols);
    std::cout << "请输入矩阵A" << endl;
    std::cin >> A;

    std::cout <<"请输入矩阵B的行和列" ;
    std::cin >> rows >> cols;
    Matrix B(rows, cols);
    std::cout << "请输入矩阵B" << endl;
    std::cin >> B;

    std::cout << "A * B = "<< endl << A * B;

    return 0;
}
