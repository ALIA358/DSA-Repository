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

 // maximum in array
   
   int max = array[0] , index=0;
   for(int i=0; i<size; i++){   
       if(array[i]>max){
       	max = array[i] ;
       	index = i;
	   }
   }
   cout<<"Maximum value in array is "<<max<<" at index "<<index;
   cout<<endl<<endl;	
   
   
 //min in array
   int min = array[0] , ind =0;
  
   for(int i=0; i<size; i++){   
       if(array[i]<min){
       	min = array[i] ;
       	ind = i;
	   }
   }
   cout<<"Minimum value in array is "<<min<<" at index "<<ind;



return 0;
}