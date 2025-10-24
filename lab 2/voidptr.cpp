#include<iostream>
using namespace std;
int main(){


int a = 10; 
char b = 'x';
void *p = &a; // void pointer holds address of int 'a' p = &b; 

    cout<<p<<endl;  //0x78fe44 
    
      p = &b;
      
    cout<<p<<endl;   // 0x78fe43

      
      

return 0;
}