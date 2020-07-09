// Fibonacci Pattern

#include<iostream>
using namespace std;

int main(int argc, char** argv){
    int n;
    cin >> n;

    int a = 0, b = 1;
    for(int r = 1; r <= n; r++){
        for(int c = 1; c <= r; c++){
            cout<<a<<"\t";
            int fib = a + b;
            a = b;
            b = fib;
        }
        cout<<endl;
    }

    return 0;
}
// reviewed