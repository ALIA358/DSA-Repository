#include <iostream>
using namespace std;

int main() {
 
 int rows, cols , sum=0;
 int matrix[rows][cols];
 
//input no.'s
    cout << "Enter rows and columns: "<<endl;
    cin >> rows >> cols;
    cout << "Enter the values: "<<endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >>matrix[i][j];
            sum+=matrix[i][j];
        }
    }
//sum of all elements
  cout<<"Sum is "<<sum<<endl;
  
//output
  cout << "Matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
 return 0;
}