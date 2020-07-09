#include <iostream>
using namespace std;

void pi(int n){
    if(n == 0){
        return;
    }

    pi(n-1);
    cout << n << endl;
}

void pd(int n){
    if(n == 0){
        return;
    }

    cout << n << endl;
    pd(n-1);
}

void pdi(int n){

    if(n == 0){
        return;
    }

    cout << n << endl;

    pdi(n-1);

    cout << n << endl;
}

int main(int argc, char** argv){
    pd(5);
    cout << endl;

    pi(5);
    cout << endl;
    
    pdi(5);
    cout << endl;

    return 0;
}