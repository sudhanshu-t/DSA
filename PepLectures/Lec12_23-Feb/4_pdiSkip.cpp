#include <iostream>
using namespace std;

void pdis(int n){
    if(n == 0){
        return;
    }

    if(n % 2 != 0){
        cout << n << endl;
    }

    pdis(n-1);

    if(n % 2 == 0){
        cout << n << endl;
    }
}

int main(int argc, char** argv){
    pdis(6);
}