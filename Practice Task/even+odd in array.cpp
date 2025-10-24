#include<iostream>
using namespace std;
int main(){

   int size = 10;
   int array[size] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 } ;

   cout<<"********* Traversing array *********"<<endl;
   for(int i=0; i<size; i++){   
       cout<<array[i]<<" ";
   }
   cout<<endl<<endl;	

 // odd values in array
   
   int  odd=0;
   cout<<"Odd values in array are "<<endl;
   for(int i=0; i<size; i++){   
       if(array[i]%2 !=0){
       	cout<<array[i]<<endl;
       	odd++;
	   }
   } 
   cout<<" NO. of Odd values in array are "<<odd; 
   cout<<endl<<endl;	
   
   
 //even in array
   int  even=0;
   cout<<"Even values in array are "<<endl;
   for(int i=0; i<size; i++){   
       if(array[i]%2 ==0){
       	cout<<array[i]<<endl;
       	even++;
	   }
   } 
   cout<<" NO. of Even values in array are "<<even; 
   cout<<endl<<endl;	
return 0;
}