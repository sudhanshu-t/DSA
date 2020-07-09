#include <iostream>
using namespace std;

void toh(char s, char d, char h, int n){
    if(n == 0){
        return;
    }

    toh(s, h, d, n-1);
    cout << "Move disc " << n << " from " << s << " to " << d << endl;
    toh(h, d, s, n-1);
}

int main(int argc, char** argv){
    toh('A', 'B', 'C', 3);
}