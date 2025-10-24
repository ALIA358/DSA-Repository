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

   // Ascending Order
   for(int i=0; i<size-1; i++){
       for(int j=0; j<size-i-1; j++){
           if(array[j] > array[j+1]){
               swap(array[j], array[j+1]);
           }
       }
   }
   cout<<"********* In Ascending Order *********"<<endl;
   for(int i=0; i<size; i++){   
       cout<<array[i]<<" ";
   }
   cout<<endl<<endl;

   // Descending Order
   for(int i=0; i<size-1; i++){
       for(int j=0; j<size-i-1; j++){
           if(array[j] < array[j+1]){
               swap(array[j], array[j+1]);
           }
       }
   }
   cout<<"********* In Descending Order *********"<<endl;
   for(int i=0; i<size; i++){   
       cout<<array[i]<<" ";
   }
   cout<<endl<<endl;

   return 0;
}
