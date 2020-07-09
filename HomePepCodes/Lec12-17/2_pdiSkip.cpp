#include <iostream>
using namespace std;

void pdiskip(int n){
    if(n == 0){
        return;
    }

    if((n & 1) != 0){
        cout << n << endl;
    }

    pdiskip(n-1);

    if((n & 1) == 0){
        cout << n << endl;
    }
}

int main(int argc, char** argv){
    pdiskip(5);
}