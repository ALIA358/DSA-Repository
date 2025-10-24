#include <iostream>
using namespace std;

// Pass by value
void cube(int x) {
    x = x * x * x;
    cout << x << endl;
}

/*// Pass by reference
void cube(int &x) {   // y and &x refer to same value at address
    x = x * x * x;
    cout << x << endl;
}*/

// Pass by pointer
void cube(int *x) {
    *x = (*x) * (*x) * (*x);
    cout << *x << endl;
}

int main() {
    int y = 10;

    // Pass by value            (copy banti hai, y change nahi hota)
    cube(y);                 
    cout << y << endl;

    // Pass by reference        (original y change ho jaata hai)
   /* cube(y);
    cout << y << endl;*/

    // Pass by pointer    (address bhejte hain, aur y phirse change ho jaata hai)
    cube(&y);
    cout << y << endl;

    return 0;
}
