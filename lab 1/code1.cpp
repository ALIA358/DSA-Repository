#include<iostream>
using namespace std;
int main(){
  /*Write a program that lets a maker of chips and salsa keep track of sales for five different types of salsa: mild, medium, sweet, hot, and zesty. 
The program should use two parallel 5-element arrays: an array of strings that holds the five salsa names and an array of integers that holds 
the number of jars sold during the past month for each salsa type. The salsa names should be stored using an initialization list at the time
 the name array is created.
The program should prompt the user to enter the number of jars sold for each type. Once this sales data has been entered,
 the program should produce a report that displays sales for each salsa type, total sales, and the names of the highest selling and lowest selling products. 
Input Validation: Do not accept negative values for number of jars sold.
*/
   string salsa[5] = {"mild", "medium", " sweet", "hot", "zesty"};
   int jars[5] , highest , lowest, max=0, min=0, totalSales=0;
   
   
   cout<<"Enter number of jars sold for each type : "<<endl;      //input array
   for(int i=0; i<5; i++){
   	cout<<i+1<<". "<<salsa[i]<<" : ";
   	cin>>jars[i];
   	if(jars[i]<0){ cout<<"Negetive value not acceptable!"<<endl; return 0;
	   }
   	 cout<<endl;
   	 totalSales+=jars[i];
   }
 
    //display
    cout<<"Sales for each salsa type : "<<endl;
    for(int i=0; i<5; i++){
    	for(int j=0; j<5;j++){
    		if(i==j){
    		cout<<i+1<<". "<<salsa[i]<<" : "<<jars[j]<<" salses."<<endl;	
			}
		}
	}cout<<endl;
    
    //totalSales
    cout<<"Total Sales for all salsa : "<<totalSales<<endl;
    
    //highest selling product
    highest = jars[0];
    lowest = jars[0];
    for(int i=1; i<5; i++){
    	if(highest < jars[i]){highest = jars[i] ; max=i;}
		if(lowest > jars[i]){lowest = jars[i] ; min=i;}
	}
    cout<<"Highest selling product : "<<salsa[max]<<endl;
    cout<<"Lowest selling product : "<<salsa[min]<<endl;


return 0;}