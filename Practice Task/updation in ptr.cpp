/* Q1. Declare an int variable and a pointer to it. use the pointer to modify the value of the integer then print the updated value.*/
#include <iostream>
using namespace std;

void update(int *p1){
	*p1 = 20;
	cout<<"Updted value of a is "<<*p1;
}

int main() {

    int a = 10   ; 
    
    int* p1 = &a; 
    
    cout<<"Value of a is "<<*p1<<endl;
    
    update(p1);
    
  return 0;
}
