#include <iostream>
using namespace std;

void pzz(int n){
    if(n == 0){
        return;
    }

    cout << n << " ";
    pzz(n-1);
    cout << n << " ";
    pzz(n-1);
    cout << n << " ";

}

int main(int argc, char** argv){
    pzz(3);
}