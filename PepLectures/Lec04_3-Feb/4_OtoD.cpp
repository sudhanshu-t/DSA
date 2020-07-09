#include <iostream>
using namespace std;

int main(int argc, char** argv){
    int oct;
    cin >> oct;
    
    // Dividing by 2 and making a number which will be reversed
    int power = 1; // that is 8 ^ 0
    int dec = 0, rem;

    while(oct != 0){
        rem = oct % 10;
        oct = oct / 10;

        dec = dec + rem * power;
        power *= 8; 
    }

    cout << dec <<endl;
    return 0;
}