#include <iostream>
using namespace std;

int main(int argc, char** argv){
    int bin;
    cin >> bin;

    int rem, oct = 0;
    int power = 1; // 0th Power of 10

    while(bin != 0){
        rem = bin % 1000;
        bin /= 1000;

        if(rem == 0)
            rem = 0;
        else if(rem == 1)
            rem = 1;
        else if(rem == 10)
            rem = 2;
        else if(rem == 11)
            rem = 3;
        else if(rem == 100)
            rem = 4;
        else if(rem == 101)
            rem = 5;
        else if(rem == 110)
            rem = 6;
        else
            rem = 7;
        
        oct += power * rem;
        power *= 10;
    }

    cout << oct <<endl;
    return 0;
}