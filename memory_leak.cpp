#include <cctype>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// tran bo nho
void stack_overflow(){
        stack_overflow();
}
// het bo nho (OOM)
void out_of_memory(){

}
// memory leak ( ro ri bo nho)
void memory_leak(){

}


int main(){
 cout << "./memory_lab stack_overflow"<<endl;
 cout << "./memory_lab out_of_memory"<<endl;
 cout << "./memory_lab memory_leak"<<endl;
 cout << ("Chose error memory to demo(q to Quit): ");
 string chose;
 cin >> chose;
 for(auto& x: chose ){
        x = tolower(x);
 }
 string lower = chose;
        if(lower =="q"){
                cout <<"Good bye"<<endl;

        }else if(lower =="./memory_lab stack_overflow"){
                cout <<"Demo stack_overflow"<<endl;

        }else if(lower=="./memory_lab out_of_memory"){
                cout <<"Demo out_of_memory"<<endl;

        }else if(lower=="./memory_lab memory_leak"){
                cout <<"Demo memory_leak"<<endl;

        } else {

        }

 return 0;
}
