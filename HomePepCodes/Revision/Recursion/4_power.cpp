#include <iostream>
using namespace std;

int power(int x, int y){
    if(y == 1){
        return x;
    }

    int a = power(x, y / 2);
    
    if(y % 2 == 0){
        return a * a;
    } else {
        return x * a * a;
    }
}

int main(int argc, char** argv){
    cout << power(4, 4) << endl;
}