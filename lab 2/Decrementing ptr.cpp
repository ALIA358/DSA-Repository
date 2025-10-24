#include<iostream>
using namespace std;
int main(){
	 
	const int  size = 3;
	int var[size] = { 5, 10, 15 };
	  int *ptr;
	  
	  ptr = &var[size-1];  //to assign last value we use & for 1st value its not necessary like prevoius code
	  
	 for(int i=0; i<size; i++){
	 	
	 	cout<<" Address : var "<<i<<" : "<<ptr<<endl;
	 	
	    cout<<" Value : var "<<i<<" : "<<*ptr<<endl;
	    
	    ptr--;
	 }
	
	
	
	return 0;
}



	 