#include <iostream>
using namespace std;

int main(int argc, char** argv){
    long int oct;
    cin >> oct;

    int power = 1; // 0th power of 1000
    int rem;
    long long int bin = 0;

    while(oct != 0){
        rem = oct % 10;
        oct = oct / 10;

        if(rem == 0){
            rem = 0;
        } else if(rem == 1){
            rem = 1;
        } else if(rem == 2){
            rem = 10;
        } else if(rem == 3){
            rem = 11;
        } else if(rem == 4){
            rem = 100;
        } else if(rem == 5){
            rem = 101;
        } else if(rem == 6){
            rem = 110;
        } else {
            rem = 111;
        }

        bin = bin + rem *  power;
        power *= 1000;
    }

    cout << bin <<endl;
    return 0;
}