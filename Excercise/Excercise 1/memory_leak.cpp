#include <bits/stdc++.h>
using namespace std;

void stack_overflow(int count){
        cout<<"Stack over flow" << count << endl;
        stack_overflow(count + 1 ); 
}

void out_of_memory(){
        try {
        while (true) {
            int *bigArr = new int[1000000000]; 
        }
    } catch (bad_alloc &e) {
        cout << "Out of memory";
    }
}

void memory_leak(){
        int* arr = new int[5000];
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
 int count = 0;
        
        if(lower =="q"){
                cout <<"Good bye"<<endl;
        }else if(lower =="./memory_lab stack_overflow"){
                cout <<"Demo stack_overflow"<<endl;
                stack_overflow(count);
        }else if(lower=="./memory_lab out_of_memory"){
                cout <<"Demo out_of_memory"<<endl;
                out_of_memory();
        }else if(lower=="./memory_lab memory_leak"){
                cout <<"Demo memory_leak"<<endl;
                memory_leak();
        } 

 return 0;
}
