#include <iostream>
#include <fstream>


const int N=3;


void printmat(const int mat[N][N]){
    for (int i=0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            std::cout << mat[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Function to add two matrices and display the result
void addmat(const int matrix1[N][N], const int matrix2[N][N], int result[N][N]) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            result[i][j] = matrix1[i][j] + matrix2[i][j];
}

// Function to subtract one matrix from another and display the result
void subtractmat(const int matrix1[N][N], const int matrix2[N][N], int result[N][N]) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            result[i][j] = matrix1[i][j] - matrix2[i][j];
}

// Function to multiply two matrices and display the result
void multmat(const int matrix1[N][N], const int matrix2[N][N], int result[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < N; ++k)
                result[i][j] += matrix1[i][k] * matrix2[k][j];
        }
    }
}

void updatemat(int matrix1[N][N], int row, int column, int value){
    if (row >= 0 && row < N && column >= 0 && column < N)
        matrix1[row][column] = value;
    else
        std::cerr << "Invalid row or column!" << std::endl;
}

void maxValue(const int matrix1[N][N]){
    int maxVal = matrix1[0][0];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if(matrix1[i][j]> maxVal){
                maxVal = matrix1[i][j];
            }
        }
    }
    std::cout << "Max Value of the matrix: " <<maxVal<<std::endl;
}

void transposemat(const int matrix1[N][N]){
    int transposedmat[N][N];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
                transposedmat[j][i] = matrix1[i][j];
        }
    }
    std::cout << "Transposed matrix:" << std::endl;
    printmat(transposedmat);
    }


int main(){
    int mat1[N][N] = {
        {1,2,3}, 
        {4, 5, 6}, 
        {7, 8, 9}
    };
    int mat2[N][N] = {
        {2, 3, 4}, 
        {5, 6, 7}, 
        {8, 9, 10}
    };
    int result[N][N];
    int row;
    int col;
    int value;

    std::cout << "Matrix 1:"<< std::endl;
    printmat(mat1);

    std::cout << "Matrix 2:"<< std::endl;
    printmat(mat2);

    addmat(mat1, mat2, result);
    std::cout << "Addition Result:" << std::endl;
    printmat(result);

    subtractmat(mat1, mat2, result);
    std::cout << "Subtraction Result:" << std::endl;
    printmat(result);

    multmat(mat1, mat2, result);
    std::cout <<"Multiplication Result:" << std::endl;
    printmat(result);

    printf("Enter the row value of the value you want to update: ");
    scanf("%d", &row);

    printf("Enter the column value of the value you want to update: ");
    scanf("%d", &col);

    printf("Enter the new value of the spot you want to update: ");
    scanf("%d", &value);
    updatemat(mat1, row, col, value);
    printmat(mat1);

    maxValue(mat1);

    transposemat(mat1);
    
}
