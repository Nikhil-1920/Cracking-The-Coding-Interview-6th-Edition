// converts all rows and columns(with zero element), to zero in matrix
#include <iostream>
using namespace std;

// converts all elements of row into 0
void nullifyRow(int **matrix, int n, int row) {
    for(int j = 0; j < n; j++) 
        matrix[row][j] = 0;
}

// converts all elements of column into 0
void nullifyCol(int **matrix, int m, int col) {
    for(int i = 0; i < m; i++)
        matrix[i][col] = 0;
}

// set all rows and columns(with zero element),
// to zero in the matrix
void setZero(int **matrix, int m, int n) {
    bool row1 = false;
    
    for(int i = 0; i < n; i++) {
        if(matrix[0][i] == 0) {
            row1 = true;
            break;
        }
    }
  
    for(int i = 1; i < m; i++) {
        bool nullifyTheRow = false;
        
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] == 0) {
                matrix[0][j] = 0;
                nullifyTheRow = true;
            }
        }
        
        if(nullifyTheRow) 
            nullifyRow(matrix, n, i);
    }
    
    for(int j = 0; j < n; j++) {
        if(matrix[0][j] == 0)
            nullifyCol(matrix, m, j);
    }
    
    if(row1) 
        nullifyRow(matrix, n, 0);
}

// function to display matrix
void printMatrix(int **matrix, int m, int n) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

int main(void) {
    int m, n;
    
    cout << "Enter number of rows: ";
    cin >> m;
    cout << "Enter number of cols: ";
    cin >> n;
    
    int **matrix = new int*[m];
    
    for(int i = 0; i < m; i++) {
        matrix[i] = new int[n];
    }
    
    cout << "\nPush m x n matrix: \n";
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    
    cout << "\nMatrix before: \n";
    printMatrix(matrix, m, n);
    
    setZero(matrix, m, n);
    
    cout << "\nMatrix after: \n";
    printMatrix(matrix, m, n);
    return 0;
}
