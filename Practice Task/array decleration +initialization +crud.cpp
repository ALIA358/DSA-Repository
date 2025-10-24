#include<iostream>
using namespace std;
int main(){
	
// array decleration + initialization
	int max = 11;
	int array[max] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 } ;
	int size = 10;


	                        //********* CRUD OPERATIONS************
	                        
// read in array / traverse an array
        cout<<"*********"<<"Traversing array "<<"*********"<<endl;
    	for(int i=0; i<size; i++){   
		cout<<array[i]<<" ";
	   }cout<<endl<<endl;;	                        
	                        
// update array
	
	int newValue = 99;
	int index = 4;
	
	array[index] = newValue;
	cout<<"*********"<<" After updating array *********"<<endl;
	for(int i=0; i<size; i++){   // traversing
		cout<<array[i]<<" ";
	}cout<<endl<<endl;
	
// delete array
	
	int delValue = 70;
	int position = 6;
	for(int i=position; i<size ; i++){
		array[i]= array[i+1];
	}
	size--;
	cout<<"*********"<<"After deletion in an array "<<"*********"<<endl;
	for(int i=0; i<size; i++){   // traversing
		cout<<array[i]<<" ";
	}cout<<endl<<endl;
	
//search in array
	int val = 20;
	cout<<"*********"<<"search in array "<<"*********"<<endl;
	for(int i=0; i<size; i++){   
		if(array[i] == val){
			cout<<"Value found at index "<<i<<endl;
		}
	}cout<<endl<<endl;	
	
// insertion in array
	int insertValue = 88;
	int pos = 3;
	for(int i=size; i>pos ; i--){
		array[i]= array[i-1];
	}
	array[pos] = insertValue;
	size++;
	cout<<"*********"<<"After insertion in an array "<<"*********"<<endl;
	for(int i=0; i<size; i++){   // traversing
		cout<<array[i]<<" ";
	}cout<<endl<<endl;
	
	
	return 0;
}