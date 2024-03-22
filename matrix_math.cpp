#include <stdio.h>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

// input, modify, output
//function will read a file for integers and place each delimited integer into the 2 matrices
void read_matrix_from_file(const string &file_name, vector<vector<int>> &matrix1, vector<vector<int>> &matrix2) {
    fstream matrix_stream(file_name);
    size_t matrix_size;
    matrix_stream >> matrix_size;

    matrix1 = vector<vector<int>>(matrix_size, vector<int>(matrix_size));
    matrix2 = vector<vector<int>>(matrix_size, vector<int>(matrix_size));

    for(int i = 0; i < matrix_size; ++i) {
        for(int j = 0; j < matrix_size; ++j) {
             matrix_stream >> matrix1[i][j];
        }
    }

    for(int i = 0; i < matrix_size; ++i) {
        for(int j = 0; j < matrix_size; ++j) {
             matrix_stream >> matrix2[i][j];
        }
    }

    matrix_stream.close();
}
//takes input matrix and prints each integer in the matrix
void print_matrix(const vector<vector<int>> &matrix) {
    for(int i = 0; i < matrix.size(); ++i) {
        for(int j = 0; j < matrix.front().size(); ++j) {
            printf("%-3d ", matrix[i][j]);
        }
        printf("\n");
    }
}
//takes 2 matrices as inputs and adds each element together and prints results
void add_matrices(const vector<vector<int>> &matrix1, const vector<vector<int>> &matrix2){
    vector<vector<int>> results = matrix1;
    for(int i = 0; i < matrix1.size(); ++i){
        for(int j = 0; j < matrix1.front().size(); ++j){
            results[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    print_matrix(results);
}
//takes 2 matrices as inputs and multiplies the matrices using the dot product of the specified row and column to a new matrix and prints results
void multiply_matrices(const vector<vector<int>> &matrix1, const vector<vector<int>> &matrix2){
    vector<vector<int>> results = matrix1;
    for(int i = 0; i < results.size(); i++){
        std::fill(results[i].begin(), results[i].end(), 0);
    }
    for(int i = 0; i < matrix1.size(); ++i){ //index rows
        for(int j = 0; j < matrix1.front().size(); ++j){ //index cols
            for(int k = 0; k < matrix1.size(); ++k){
                results[i][j] = results[i][j] + matrix1[i][k] * matrix2[k][j];//k is used to move through the dot product for row,col i,j
            }
        }
    }
    print_matrix(results);
}
//takes 2 matrices as inputs and subtracts each element to a new matrix and prints the result
void subtract_matrices(const vector<vector<int>> &matrix1, const vector<vector<int>> &matrix2){
    vector<vector<int>> results = matrix1;
    for(int i = 0; i < matrix1.size(); ++i){
        for(int j = 0; j < matrix1.front().size(); ++j){
            results[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    print_matrix(results);
}
//takes a matrix as the input then asks the user for a val, row, and col to update a specific element of the matrix then prints the results
void update_matrix(vector<vector<int>> &matrix1){
    int val, row, col = 0;
    printf("val: ");
    scanf("%d", &val);
    printf("\nrow: ");
    scanf("%d", &row);
    if(row > matrix1.size()){
        printf("row out of bounds, please enter a new row: ");
        scanf("%d", &row);
    }
    printf("\ncol: ");
    scanf("%d", &col);
    if(col > matrix1.front().size()){
        printf("col out of bounds, please enter a new col: ");
        scanf("%d", &col);
    }
    printf("\n");
    matrix1[row-1][col-1] = val;
    print_matrix(matrix1);
}
//takes a matrix as an input then calculates the maximum value by interating through all values in the matrix then prints the result
void max_value(const vector<vector<int>> &matrix1){
    int max = 0;
    for(int i = 0; i < matrix1.size(); i++){
        for(int j = 0; j < matrix1.front().size(); j++){
            if(matrix1[i][j] > max){
                max = matrix1[i][j];
            }
        }
    }
    printf("The maximum value of the matrix is: %d\n", max);
}
//takes a matrix as an input then transposes that matrix and prints the results
void transpose_matrix(vector<vector<int>> &matrix1){
    vector<vector<int>> temp = matrix1;
    for(int i = 0; i < matrix1.size(); i++){
        for(int j = 0; j < matrix1.front().size(); j++){
            matrix1[i][j] = temp[j][i];
        }
    }
    print_matrix(matrix1);
}

int main() { //main runs a sample of each function to show functionality
    vector<vector<int>> matrix1, matrix2, matrix3;
    read_matrix_from_file(string("matrix_input.txt"), matrix1, matrix2); //file must be 2 square matrices with the size given at the top line of the file
    printf("matrix 1\n");
    print_matrix(matrix1);
    printf("matrix 2\n");
    print_matrix(matrix2);
    printf("add matrix\n");
    add_matrices(matrix1, matrix2);
    printf("multiply matrix\n");
    multiply_matrices(matrix1, matrix2);
    printf("subtract matrix\n");
    subtract_matrices(matrix1, matrix2);
    printf("update matrix\n");
    update_matrix(matrix1);
    max_value(matrix1);
    printf("transpose matrix\n");
    transpose_matrix(matrix1);

    return 0;
}
