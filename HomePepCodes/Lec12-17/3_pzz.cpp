#include <iostream>
using namespace std;

void pzz(int n){
    if(n == 0){
        return;
    }

    cout << n << endl;
    pzz(n-1);
    cout << n << endl;
    pzz(n-1);
    cout << n << endl;
}

int main(int argc, char** argv){
    pzz(3);
}