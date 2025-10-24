#include<iostream>
using namespace std;
int main(){
	
	int a=80;
	int *ptr=&a;
	int **p=&ptr;   // double pointer
	
	cout<<" a  :"<<a<<endl;
	cout<<" *ptr :"<<*ptr<<endl;  // *(&a)
	cout<<" **p :"<<**p<<endl;    // *(&ptr)
	

	return 0;
}