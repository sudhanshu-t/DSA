#include<iostream>

using namespace std;

int main(){
    int a = 10;
    int b = 20;
    int c = 30;

    if(a >= b && a >= c){
        cout<<"a = "<< a <<" is largest."<<endl;
    } else{
        if(b >= c){
            cout<<"b = "<< b <<" is largest."<<endl;
        } else{
            cout<<"c = "<< c <<" is largest."<<endl;
        }
    }

    return 0;
}