#include <iostream>
using namespace std;

void toh(char src, char dest, char help, int n){
    if(n == 0){
        return;
    }

    toh(src, help, dest, n-1);
    cout << "Move " << n << " from " << src << " to " << dest << endl;
    toh(help, dest, src, n-1);
}

int main(int argc, char** argv){
    toh('A', 'B', 'C', 3);
}