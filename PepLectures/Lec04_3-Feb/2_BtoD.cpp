#include <iostream>
using namespace std;

int main(int argc, char** argv){
    int bin;
    cin >> bin;
    
    // Dividing by 10 and making a number which will be reversed
    int power = 1; // that is 2 ^ 0
    int dec = 0, rem;

    while(bin != 0){
        rem = bin % 10;
        bin = bin / 10;

        dec = dec + rem * power;
        power *= 2; 
    }

    cout << dec <<endl;
    return 0;
}