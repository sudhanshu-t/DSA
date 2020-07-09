#include <iostream>
using namespace std;

int main(int argc, char** argv){
    int o1, o2, r1, r2;
    cin >> o1 >> o2;

    int power = 1; // 0th power of 10
    int sum = 0, carry = 0, digit;

    while(o1 != 0 || o2 != 0 || carry != 0){
        r1 = o1 % 10;
        o1 /= 10;
        r2 = o2 % 10;
        o2 /= 10;

        if(r1 + r2 + carry >= 8){
            digit = r1 + r2 + carry - 8;
            carry = 1;
        } else {
            digit = r1 + r2 + carry;
            carry = 0;
        }

        sum += digit * power;
        power *= 10;
    }

    cout << sum <<endl;

    return 0;
}