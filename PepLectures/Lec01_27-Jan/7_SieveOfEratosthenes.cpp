#include<iostream>
using namespace std;

int main(){
    int sieve[100];

    for(int i = 0 ; i < 100; i++){
        sieve[i] = i+1;
    }

    for(int i = 2; i <= 10; i++){
        for(int j = 2; i*j <= 100; j++){
            sieve[i*j] = 0;
        }
    }

    for(int i = 0; i < 100; i++){
        cout<<i;
        
        if(sieve[i])
            cout<<" - Prime"<<endl;

        else
            cout<<" - Non-Prime"<<endl;
    }

    return 0;
}