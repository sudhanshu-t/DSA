#include <iostream>
#include <ctime>
using namespace std;

int power(int x, int n){
    if(n == 0){
        return 1;
    }

    if(x == 0){
        return 0;
    }

    //x *= power(x, n-1);
    
///// More efficient approach - Multiplies just n/2 times instead of n times as the previous one did.
    if((n&1) == 0)
        x = power(x, n/2) * power(x, n/2);
    else
    {
        x = x * power(x, n/2) * power(x, n/2);
    }
    
    return x;

    // return x;
}

int main(int argc, char** argv){
    cout << power(3, 6) << endl;

    // cout << clock << endl;
}