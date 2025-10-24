#include <iostream>
using namespace std;

int main() {                         //Dynamic 2D Array
    int rows, cols;
    cout << "Enter rows and columns: ";
    cin >> rows >> cols;

    // Dynamic 2D array 
    int **matrix = new int*[rows];   // rows  pointers
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];   // har row ke liye columns
    }

    // Values input  
    cout << "Enter values for matrix: \n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    // Print  
    cout << "Matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Memory free  
    for (int i = 0; i < rows; i++) {
        delete [] matrix[i];   // har row ko free karo
    }
    delete [] matrix;        // phir rows ka array free karo

    return 0;
}
