#include<iostream>
using namespace std;

struct student{
	int age ;
	char name[15];
		
		   struct roll_no{
		   	char dep[5];
		   	char degree[5];
		   	int session;
		   	int no;		
		   } rn ;		
	};
	
int main(){
	 student s1;
	 
	 cout<<"Enter the name "<<endl;    //input
     cin>>s1.name;
     
     cout<<"Enter the age "<<endl;
     cin>>s1.age;
     
     cout<<"Enter the roll no. "<<endl;
     cout<<"Enter the department "<<endl;
     cin>>s1.rn.dep;
     
     cout<<"Enter the session "<<endl;
     cin>>s1.rn.session;
     
     cout<<"Enter the no. "<<endl;
     cin>>s1.rn.no;
     
     cout<<"Enter the degree "<<endl;
     cin>>s1.rn.degree;
     
     //display 
     
     cout<<"Name "<<s1.name<<endl;
     cout<<"Age "<<s1.age<<endl;
     cout<<"Department "<<s1.rn.dep<<endl;
     cout<<"Session "<<s1.rn.session<<endl;
     cout<<"No. "<<s1.rn.no<<endl;
     cout<<"Degree. "<<s1.rn.degree<<endl;
     
     
    student *ptr = &s1;  
    cout << ptr->name;   //-> (arrow operator) sirf pointer to structure ke saath use hota hai.
    cout << ptr->rn.dep; 
     
   /*•	The Dot(.) operator is used to normally access members of a structure.
•	The Arrow(->) operator exists to access the members of the structure using pointers.

*/  
     
     
     
	
	return 0;
}