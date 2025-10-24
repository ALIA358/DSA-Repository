#include <iostream>
using namespace std;
int main() {
	
    int arr[5] = {10, 20, 30, 40, 50};   

    int *p = arr; // p = address of arr[0]

    cout << "Initial pointer (p) points to value: " << *p << endl;

// Arithmetic operations

// 1. Increment
    p++;
    cout << "After p++ ( arr[1]): " << *p << endl;

// 2. Decrement
    p--;
    cout << "After p-- ( arr[0]): " << *p << endl;

// 3. Addition
    p = p + 3; // p = arr[3]
    cout << "After p + 3 ( arr[3]): " << *p << endl;

// 4. Subtraction
    p = p - 2; //  p = arr[1]
    cout << "After p - 2 ( arr[1]): " << *p << endl;

// 5. Pointer difference
    int *p1 = &arr[1];
    int *p2 = &arr[4];
    cout << "p2 - p1 (distance in elements): " << (p2 - p1) << endl;

// 6. Pointer comparison
    
    cout << "p1 points to: " << *p1 << endl;
    cout << "p2 points to: " << *p2 << endl;

    
    if (p1 < p2) {
        cout << "true" << endl;
    } else{  cout << "false" << endl;}

    if (p2 > p1) {
        cout << "true" << endl;
    }else{  cout << "false" << endl;} 
    
    if (p1 != p2) {
        cout << "true" << endl;
    }else{  cout << "false" << endl;}
   
    p1 = p1 + 3; // now p1 points to arr[4] too

    if (p1 == p2) {
        cout << "true" << endl;
    }else{  cout << "false" << endl;}

    return 0;
}
