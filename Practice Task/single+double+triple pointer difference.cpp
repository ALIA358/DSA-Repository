#include <iostream>
using namespace std;

int main() {
    int x = 42;

    // single pointer
    int *p = &x;

    // double pointer
    int **pp = &p;

    // triple pointer
    int ***ppp = &pp;

    cout << "Value of x: " << x << endl;

    cout << "Using *p: " << *p << endl;         // single dereference
    cout << "Using **pp: " << **pp << endl;     // double dereference
    cout << "Using ***ppp: " << ***ppp << endl; // triple dereference

    return 0;
}
/*
                       Double Pointer (`**`)                      Triple Pointer (`***`)                         

  Definition           Pointer to a pointer                        Pointer to a double pointer                     
  What it stores?      Address of a single pointer                 Address of a double pointer                     
  Declaration          int **pp;`                                  int ***ppp;`                                  
  Initialization       pp = &p;` (where `p` is `int*`)             ppp = &pp;` (where `pp` is `int**`)           
  Dereferencing        **pp` gives the actual value (`int`)        ***ppp` gives the actual value (`int`)     
  Typical Use          Dynamic 2D arrays,managing pointer arrays   Complex data structures (3D arrays, callbacks) 

*/