#include <stdio.h>
#include<iostream> 
using namespace std;

void summ_Matrix(int** mtx1, int** mtx2, int** result, int n) {

#pragma omp parallel for shared(result)

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = mtx1[i][j] + mtx2[i][j];
        }
    }
}

void mult_Matrix(int** mtx1, int** mtx2, int** result, int n) {

#pragma omp parallel for shared(result)

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += mtx1[i][k] * mtx2[k][j];
            }
        }
    }

}

int rand_Matrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 5 + 0;
        }
    }
    return **matrix;
}

void print_Matrix(int** mtx, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << " " << mtx[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {

    int n = 4;

    //Матрица n x n
    int** matrix1;
    //Матрица n x n
    int** matrix2;

    matrix1 = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        matrix1[i] = (int*)malloc(sizeof(int) * n);   // выделение памяти
    }
    matrix2 = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        matrix2[i] = (int*)malloc(sizeof(int) * n);
    }
    
    int** result_sum = (int**)malloc(sizeof(int*) * n);;
    for (int i = 0; i < n; i++) {
        result_sum[i] = (int*)malloc(sizeof(int) * n);
    }

    int** result_mult = (int**)malloc(sizeof(int*) * n);;
    for (int i = 0; i < n; i++) {
        result_mult[i] = (int*)malloc(sizeof(int) * n);
    }

    rand_Matrix(matrix1, n);
    rand_Matrix(matrix2, n);
     
    summ_Matrix(matrix1, matrix2, result_sum, n);
    mult_Matrix(matrix1, matrix2, result_mult, n); 

    print_Matrix(matrix1, n);
    cout << " + " << endl;
    print_Matrix(matrix2, n);
    cout << " = " << endl;
    print_Matrix(result_sum, n);

    cout << endl;

    print_Matrix(matrix1, n);
    cout << " * " << endl;
    print_Matrix(matrix2, n);
    cout << " = " << endl;
    print_Matrix(result_mult, n);

    return 0;
}