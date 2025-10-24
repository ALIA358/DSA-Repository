#include <iostream>
using namespace std;

int main() {                  //Dynamic Memory Allocation Example (1D Array)
    int size;             
    cout << "Enter size of array: ";
    cin >> size;             // size on runtime decided

    // Dynamic allocation syntax
    int* arr = new int[size];  //  memory allocated on heap using new keyword   >>>>imp

    //  input Values 
    cout << "Enter " << size << " values: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // Print 
    cout << "Dynamic Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    // Memory free at end
    delete [] arr;

    return 0;
}
