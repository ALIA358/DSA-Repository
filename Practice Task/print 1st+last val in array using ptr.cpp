/* Q1. Declare an array of 5 int , use ptr to print 1st and last value of array.*/
#include <iostream>
using namespace std;

int main() {

    int arr[5] = {1,2,3,4,5}   ; 
    int* p1 = arr; 
    int *p2 = &arr[4];
    cout<<"1st value in array "<<*p1<<endl;
    cout<<"Last value in array "<<*p2<<endl;
    
   
  return 0;
}
