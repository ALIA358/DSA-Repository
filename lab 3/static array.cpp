#include <iostream>
using namespace std;

int main() {
                                     // Static memory allocation
    int arr[5];   //  size fix on compile time 

    
    for (int i = 0; i < 5; i++) {
        arr[i] = i + 1;  // input 1,2,3,4,5 
    }

    // Print 
    cout << "Static Array: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
