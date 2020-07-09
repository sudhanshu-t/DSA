#include <iostream>
using namespace std;

int main(int argc, char** argv){
    int dec;
    cin >> dec;
    
    // Dividing by 2 and making a number which will be reversed
    int power = 1; // that is 10 ^ 0
    int oct = 0, rem;

    while(dec != 0){
        rem = dec % 8;
        dec = dec / 8;

        oct = oct + rem * power;
        power *= 10; 
    }

    cout << oct <<endl;
    return 0;
}