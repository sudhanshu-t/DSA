#include <iostream>
using namespace std;

int main(int argc, char** argv){
    int o1, o2, r1, r2;

    cin >> o1 >> o2;

    int borrow = 0, digit, diff = 0, power = 1; // power is 0th power of 10
    while(o1 != 0 || o2 != 0 || borrow != 0){
        r1 = o1 % 10;
        r2 = o2 % 10;

        o1 /= 10;
        o2 /= 10;

        if(r1 > r2){
            digit = r1 - r2 + borrow;
            borrow = 0;
        } else {
            digit = r1 - r2 + 8 + borrow;
            borrow = -1;
        }

        diff = digit * power + diff;
        power *= 10;
    }

    cout << diff << endl;

    return 0;
}