#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter rows and columns: ";
    cin >> rows >> cols;

    
    int matrix[100][100]; 

// Input values
    cout << "Enter the values: "<<endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

// Output matrix
    cout << "Matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

// max & min
    int max = matrix[0][0];
    int min = matrix[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if(matrix[i][j] > max) max = matrix[i][j];
            if(matrix[i][j] < min) min = matrix[i][j];
        }
    }
    cout <<"Max value in array is : "<< max << endl;
    cout <<"Min value in array is : "<< min << endl;

    return 0;
}
