#include<iostream>
using namespace std;
int main(){
/*
   char str[] = "Computer";
   char *cp = str;
   
   cout<<&cp<<endl;   //address
   cout<<cp;         // Output: Computer (kyunki pointer char ki array ko string samajhta hai and \0 tk print krta hai).
   cout << *cp;   // Output: C  */


    char st[] = "Pakistan" ;

    void PrintString(char*);
    PrintString(st);
    
  
return 0;
}
void PrintString(char* sss){
       while(*sss != 0){
       cout<<*sss <<endl;
       *sss ++ ;}
	}