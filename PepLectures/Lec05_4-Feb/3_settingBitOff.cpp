#include <iostream>
using namespace std;

int main(int aragc, char** argv){
    int n;
    int k;
    
    cin >> n >> k;

    int bm = 1 << k;
    if((n & bm) == 0){
        cout << "The bit is alredy off" << endl;
    } else {
        cout << "The bit is on, the new number is :" << endl;
        cout << (n & ~bm) << endl;
    }

    return 0;
}