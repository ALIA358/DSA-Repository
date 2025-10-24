/*Write a program to pass two parameters to the function to add a constant value of 100 to the passed values using pointers.*/
#include<iostream>
using namespace std;

void add(int *a , int *b){
	*a = *a+100;
	*b = *b+100;
	cout<<" A = "<<*a<<" B = "<<*b<<endl;
}

int main(){
	
	int x=20 , y=30;
	
	cout<<" A = "<<x<<" B = "<<y<<endl;
	
    add(&x , &y);
	
		
	return 0;
}

