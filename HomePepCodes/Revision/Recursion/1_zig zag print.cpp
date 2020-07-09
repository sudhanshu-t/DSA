#include <iostream>
using namespace std;

void print_zig_zag(int n){
    if(n == 0){
        return;
    }
    
    cout << n << " ";
    print_zig_zag(n-1);
    cout << n << " ";
    print_zig_zag(n-1);
    cout << n << " ";
}

int main(int argc, char** argv){
    print_zig_zag(3);
}