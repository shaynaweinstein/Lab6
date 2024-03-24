#include <iostream>
#include <fstream>



void readMatFile(int matrix[][10],  int& dim, const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        file >> dim; // Read the size of the square matrix
        if (dim > 10 || dim <= 0) {
            std::cerr << "Invalid matrix size!" << std::endl;
            return;
        }
        for (int i = 0; i < dim; ++i)
            for (int j = 0; j < dim; ++j)
                file >> matrix[i][j];
        file.close();
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}


void printmat(const int mat[][10], int size){
    for (int i=0; i < size; ++i){
        for (int j = 0; j < size; ++j){
            std::cout << mat[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Function to add two matrices and display the result
void addmat(const int matrix1[][10], const int matrix2[][10], int result[][10], int size) {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            result[i][j] = matrix1[i][j] + matrix2[i][j];
}

// Function to subtract one matrix from another and display the result
void subtractmat(const int matrix1[][10], const int matrix2[][10], int result[][10], int size) {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            result[i][j] = matrix1[i][j] - matrix2[i][j];
}

// Function to multiply two matrices and display the result
void multmat(const int matrix1[][10], const int matrix2[][10], int result[][10], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < size; ++k)
                result[i][j] += matrix1[i][k] * matrix2[k][j];
        }
    }
}

void updatemat(int matrix1[][10], int row, int column, int value, int size){
    if (row >= 0 && row < size && column >= 0 && column < size)
        matrix1[row][column] = value;
    else
        std::cerr << "Invalid row or column!" << std::endl;
}

void maxValue(const int matrix1[][10], int size){
    int maxVal = matrix1[0][0];
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if(matrix1[i][j]> maxVal){
                maxVal = matrix1[i][j];
            }
        }
    }
    std::cout << "Max Value of the matrix: " <<maxVal<<std::endl;
}

void transposemat(const int matrix1[][10], int size){
    int transposedmat[10][10];
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
                transposedmat[j][i] = matrix1[i][j];
        }
    }
    std::cout << "Transposed matrix:" << std::endl;
    printmat(transposedmat, size);
    }


int main(){
    int mat1[10][10];
    int mat2[10][10];
    int result[10][10];
    int size;
    int row;
    int col;
    int value;

    readMatFile(mat1, size, "matrix_input.txt");
    readMatFile(mat2, size, "matrix_input.txt");


    std::cout << "Matrix 1:"<< std::endl;
    printmat(mat1, size);

    std::cout << "Matrix 2:"<< std::endl;
    printmat(mat2, size);

    addmat(mat1, mat2, result, size);
    std::cout << "Addition Result:" << std::endl;
    printmat(result, size);

    subtractmat(mat1, mat2, result, size);
    std::cout << "Subtraction Result:" << std::endl;
    printmat(result, size);

    multmat(mat1, mat2, result, size);
    std::cout <<"Multiplication Result:" << std::endl;
    printmat(result, size);

    printf("Enter the row value of the value you want to update: ");
    scanf("%d", &row);

    printf("Enter the column value of the value you want to update: ");
    scanf("%d", &col);

    printf("Enter the new value of the spot you want to update: ");
    scanf("%d", &value);
    updatemat(mat1, row, col, value, size);
    printmat(mat1, size);

    maxValue(mat1, size);

    transposemat(mat1, size);
    
}
