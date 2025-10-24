#include<iostream>
using namespace std;
int main(){
	
	int students[10];
	int n=5;
	int index , index1, index2, val, value , value1 , value2;
 //input values
	for(int i=0; i<n; i++){                  
		cin>>students[i];	
	}
	cout<<"*************************************"<<endl;
	
//output values	
	for(int j=0; j<n; j++){                 
		cout<<" Student "<<j<<" :"<<students[j]<<" marks. "<<endl;	
	}
	 
//Deletion
	 cout<<"*************************************"<<endl;
	 cout<<endl;
	 cout<<"At what index u want to delete value?"<<endl;
	 cin>>index1;
	 for(int k=index1; k<n; k++){
	   students[k]=students[k+1];	
	 }
	 n--;
	cout<<"After Deletion:"<<endl;
	  for(int j=0; j<n; j++){                 //output values
		cout<<" Student "<<j<<" :"<<students[j]<<" marks. "<<endl;  	
}


 //insertion  
	 
	 cout<<endl;
	 cout<<"At what index u want to insert value?"<<endl;
	 cin>>index;
	 cout<<"Insert the value:"<<endl;
	 cin>>value;
	 	
     for(int z=n; z>=index; z--){
     	
      	students[z]=students[z-1];
	 }
	  students[index] =value;  n++;
	  cout<<endl;
	  cout<<"After insertion:"<<endl;
	  for(int j=0; j<n; j++){                 //output values
		cout<<" Student "<<j<<" :"<<students[j]<<" marks. "<<endl;	
	}

//search
cout<<endl;
	  cout<<"*************************************"<<endl;
	 cout<<"What value u want to search?"<<endl;
	 cin>>value2;
	 
	 for(int i=0; i<n; i++){
	 	if(students[i]==value2){
	 		cout<<"Value found at index:"<<i<<endl;
		 }
	 }
	 
	
//Update 
	 cout<<endl;
	  cout<<"*************************************"<<endl;
	 cout<<"At what index u want to update value?"<<endl;
	 cin>>index2;
	 cout<<"Insert the value:"<<endl;
	 cin>>val;
	 students[index2] =val;
	 
	 
     cout<<"After updation:"<<endl;	
     cout<<endl;
     for(int z=0; z<=index2; z++){
     cout<<" Student "<<z<<" : "<<students[z]<<" marks. "<<endl;	
	 }
	return 0;


}