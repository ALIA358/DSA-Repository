#include<iostream>
using namespace std;
int main(){ 
   
    int array[6] = {5,3,8,15,12} , value;
     int n=5;
     
    for(int i=0; i<n; i++ ){  //display
    	cout<<array[i]<<endl;	
	}cout<<endl;
	
   cout<<"Enter the value to insert : "<<endl;  //value
   cin>>value;
     
    for(int i=n+1; i>0; i-- ){  //shifting
    	
    	array[i]=array[i-1];
    	
	} n++;
     array[0]= value;cout<<endl;   //inserting

    for(int i=0; i<n; i++ ){  //display
    	cout<<array[i]<<endl;	
	}




return 0;
}