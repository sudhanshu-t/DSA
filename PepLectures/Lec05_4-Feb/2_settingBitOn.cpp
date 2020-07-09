#include <iostream>
using namespace std;

int main(int argc, char** argv){
    int n;
    int k;

    cin >> n;
    cin >> k;

    int bm = 1 << k;
    if((n & bm) == 0){
        cout << "The bit is off, the new number is : " << endl;
        cout << (n | bm) << endl;
    }
    else {
        cout << "The bit is already on" << endl;
    }

    return 0;
}