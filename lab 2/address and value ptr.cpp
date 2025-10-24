#include<iostream>
using namespace std;

const int  size = 3;

int main(){
	

	  int var[size] = { 5, 10, 15 };
	  int *ptr;
	  
	  ptr = var;
	  
	 for(int i=0; i<size; i++){
	 	
	 	cout<<" Address : var "<<i<<" : "<<ptr<<endl;  // prints address
	 	
	    cout<<" Value : var "<<i<<" : "<<*ptr<<endl;   //prints value
	    
	    ptr++;
	 }
	 
	return 0;
}