#include <iostream>

using namespace std;

int main(int argc, char** argv){
    int n;
    cin >> n;

    int rsbm = 0, count = 0;
    while(n != 0){
        rsbm = (n & (-n));
        n = n - rsbm; // is equivalent to n = n ^ rsbm;
        count++;
    }

    cout << count << endl;
    return 0;
}