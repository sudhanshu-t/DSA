#include <iostream>
using namespace std;

int main(int argc, char** argv){
    int dec;
    cin >> dec;
    
    // Dividing by 2 and making a number which will be reversed
    int power = 1; // that is 10 ^ 0
    int bin = 0, rem;

    while(dec != 0){
        rem = dec % 2;
        dec = dec / 2;

        bin = bin + rem * power;
        power *= 10; 
    }

    cout << bin <<endl;
    return 0;
}