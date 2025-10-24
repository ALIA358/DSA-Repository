#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    int matrix[100][100];

// Create / Input
    cout << "Enter rows and columns: ";
    cin >> rows >> cols;
    cout << "Enter the values: " << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

// Traverse / Read
    cout << "Matrix:"<<endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

//  Insert 
    int row, col, val;
    cout << "Enter the position to insert (row and col): ";
    cin >> row >> col;
    cout << "Enter the value: ";
    cin >> val;

    if (row < rows && col < cols) {
        matrix[row][col] = val;  
    } else {
        cout << "Invalid position!" << endl;
    }

    cout << "After Insertion/Updation:"<<endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

//  Delete 
    int delRow, delCol;
    cout << "Enter the position to delete (row and col): ";
    cin >> delRow >> delCol;

    if (delRow < rows && delCol < cols) {
        matrix[delRow][delCol] = 0; //set 0
    } else {
        cout << "Invalid position!" << endl;
    }

    cout << "After Deletion:"<<endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

// Search 
    int value;
    bool found = false;
    cout << "Enter value to search: ";
    cin >> value;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == value) {
                cout << "Value found at (" << i << ", " << j << ")"<<endl;
                found = true;
            }
        }
    }
    
    if (!found) {
        cout << "Value not found in the matrix."<<endl;
    }

    return 0;
}
