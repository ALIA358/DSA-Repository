/*Write a program that uses the following arrays: 
• empId: an array of seven long integers to hold employee identification numbers. The array should be initialized with the following numbers: 
            5658845 4520125 7895122 8777541 8451277 1302850 7580489 
• hours: an array of seven integers to hold the number of hours worked by each employee 
• payRate: an array of seven doubles to hold each employee’s hourly pay rate 
• wages: an array of seven doubles to hold each employee’s gross wages 

Program should relate the data in each array through the subscripts. For example, the number in element 0 of the hours array should be the number of hours 
worked by the employee whose identification number is stored in element 0 of the empId array. That same employee’s pay rate should be stored in element 0 
of the payRate array. 

The program should display each employee number and ask the user to enter that employee’s hours and pay rate. It should then calculate the gross wages 
for that employee (hours times pay rate) and store them in the wages array. After the data has been entered for all the employees, the program should 
display each employee’s identification number and gross wages. Input Validation: Do not accept negative values for hours or numbers less than 15.00 for pay rate.

*/
#include<iostream>
using namespace std;
int main(){ 

    long int empId[7] ={5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 7580489};
         int hours[7];
         double payRate[7];
         double wages[7];
         
    cout<<"Enter employees hours and pay rate : "<<endl;      //input array
    for(int i=0; i<7; i++){
   	cout<<i+1<<". "<<empId[i]<<" : hours : ";cin>>hours[i];
	     if(hours[i]<0){ cout<<"Negetive value not acceptable!"<<endl; return 0;
		 }
	   cout<<"  Pay Rate  : ";cin>>payRate[i];
	   if(payRate[i]<15){ cout<<"Numbers less than 15.00 for pay rate is not acceptable!"<<endl; return 0;
		 }
	   cout<<endl;
   	wages[i] = hours[i]*payRate[i] ;
   }
         
    //display  each employee’s identification number and gross wages    
    for(int i=0; i<7; i++){
   	cout<<i+1<<". Employee :"<<empId[i]<<" , gross wages :"<<wages[i]<<endl;
   }     
         
         
return 0; }