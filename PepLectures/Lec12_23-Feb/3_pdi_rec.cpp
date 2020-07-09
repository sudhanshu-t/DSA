#include <iostream>
using namespace std;

void pdi(int n){
    if(n == 0){
        return;
    }

    cout << n << endl;
    pdi(n-1);
    cout << n << endl;

    return;

}

int main(int argc, char** argv){
    pdi(5);

    return 0;
}