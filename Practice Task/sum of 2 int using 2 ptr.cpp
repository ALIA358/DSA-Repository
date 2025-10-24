/* Q1. Declare 2 integers and 2 pointers use the pointers to add 2 integers and print result.*/
#include <iostream>
using namespace std;
int main() {

    int a = 10 , b = 20 ;
    int *p1 = &a;
	int *p2 = &b;
    
    int sum = *p1 + *p2 ;
    cout<<"Sum of a = "<<a<<" , b = "<<b<<" is "<<sum;


return 0;
}