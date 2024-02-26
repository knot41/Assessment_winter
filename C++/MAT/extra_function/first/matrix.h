#pragma once
#include<iostream>
using namespace std;

class Matrix{
public:
    Matrix(int tmprows,int tmpcols,int ** tmpmatrix);
    Matrix(const Matrix& other);
    Matrix& operator =(Matrix& other);
    friend istream& operator >>(istream & in,const Matrix & A);
    friend ostream& operator <<(ostream & out,const Matrix & A);
    friend Matrix operator +(Matrix & A,Matrix & B);
    friend Matrix operator -(Matrix & A,Matrix & B);
    friend Matrix operator *(Matrix & A,Matrix & B);
    friend bool operator ==(Matrix & A,Matrix & B);
private:
    int rows,cols;
    int **matrix;
};
Matrix :: Matrix(int tmprows,int tmpcols,int ** tmpmatrix){
    rows = tmprows;
    cols = tmpcols;
    matrix = (int **)malloc(sizeof(int *) * rows);
    for(int i = 0;i < rows;i++){
        matrix[i] = (int *)malloc(sizeof(int) * cols);
    }
    for(int i = 0;i < rows;i++){
        for(int  j = 0;j < cols;j++){
            matrix[i][j] = tmpmatrix[i][j];
        }
    }
}
Matrix :: Matrix(const Matrix& other){
    rows = other.rows;
    cols = other.cols;
    matrix = (int **)malloc(sizeof(int *) * rows);
    for(int i = 0;i < rows;i++){
        matrix[i] = (int *)malloc(sizeof(int) * cols);
    }
    for(int i = 0;i < rows;i++){
        for(int  j = 0;j < cols;j++){
            matrix[i][j] = other.matrix[i][j];
        }
    }
}
Matrix& Matrix::operator=(Matrix& other){
    matrix = other.matrix;
    return other;
}
istream& operator >>(istream & in,const Matrix & A){
    for(int i = 0;i < A.rows;i++){
        for(int j = 0;j < A.cols;j++){
            in >> A.matrix[i][j];
        }
    }
    return in;
}
ostream& operator <<(ostream & out,const Matrix & A){
    for(int i = 0;i < A.rows;i++){
        for(int j = 0;j < A.cols;j++){
            out << A.matrix[i][j] << ' ';
        }
        out << endl;
    }
    return out;
}
Matrix operator +(Matrix & A,Matrix & B){
    int ** tmpmatrix = (int **)malloc(sizeof(int *) * A.rows);
    for(int i = 0;i < A.rows;i++){
        tmpmatrix[i] = (int *)malloc(sizeof(int) * A.cols);
    }
    for(int i = 0;i < A.rows;i++){
        for(int j = 0;j < A.cols;j++){
            tmpmatrix[i][j] = A.matrix[i][j] + B.matrix[i][j];
        }
    }
    Matrix C(A.rows,A.cols,tmpmatrix);
    return C;
}
Matrix operator -(Matrix & A,Matrix & B){
    int ** tmpmatrix = (int **)malloc(sizeof(int *) * A.rows);
    for(int i = 0;i < A.rows;i++){
        tmpmatrix[i] = (int *)malloc(sizeof(int) * A.cols);
    }
    for(int i = 0;i < A.rows;i++){
        for(int j = 0;j < A.cols;j++){
            tmpmatrix[i][j] = A.matrix[i][j] - B.matrix[i][j];
        }
    }
    Matrix C(A.rows,A.cols,tmpmatrix);
    return C;    
}
Matrix operator *(Matrix & A,Matrix & B){
    int ** tmpmatrix = (int **)malloc(sizeof(int *) * A.rows);
    for(int i = 0;i < A.rows;i++){
        tmpmatrix[i] = (int *)malloc(sizeof(int) * B.cols);
    }
    for(int i = 0;i < A.rows;i++){
        for(int j = 0;j < B.cols;j++){
            int value = 0;
            for(int k = 0;k < A.cols;k++){
                value += A.matrix[i][k] * B.matrix[k][j];
            }
            tmpmatrix[i][j] = value;
        }
    }
    Matrix C(A.rows,B.cols,tmpmatrix);
    return C;
}
bool operator ==(Matrix & A,Matrix & B){
    if(A.rows != B.cols || A.cols != B.cols) return false;
    else{
        for(int i = 0;i < A.rows;i++){
            for(int j = 0;j < A.cols;j++){
                if(A.matrix[i][j] != B.matrix[i][j]) return false;
            }
        }
        return true;
    }
}