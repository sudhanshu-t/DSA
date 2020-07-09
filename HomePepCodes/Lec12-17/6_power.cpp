#include <iostream>
using namespace std;

int power1(int m, int n){
    if(n == 0){
        return 1;
    }

    int a;

    if(n%2 == 0){
        a = power1(m, n/2) * power1(m, n/2);
    } else{
        a = m * power1(m, n/2) * power1(m, n/2);
    }

    return a;
}

int power2(int m, int n){
    if(n == 0){
        return 1;
    }
    
    int a = power2(m, n/2);

    if(n%2 == 0){
        m = a * a; 
    } else{
        m = a * a * m;
    }

    return m;
}

int main(int argc, char** argv){
    // studip power
    cout << power1(5,2) << endl;
    // smart power
    cout << power2(5,2) << endl;
}