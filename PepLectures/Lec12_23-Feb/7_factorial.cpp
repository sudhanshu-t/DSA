#include <iostream>
using namespace std;

int fact(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    
    n = n * fact(n-1);

    return n;
}

int main(int argc, char** argv){
    cout << fact(6) << endl;
}