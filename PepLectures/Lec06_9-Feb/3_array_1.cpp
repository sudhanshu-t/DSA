#include <iostream>
using namespace std;

int main(int argc, char** argv){
    int i;
    int arr[4];

    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;

    for(int i = 0; i < sizeof(arr) / sizeof(int); i++){
        cout << arr[i] << endl;
    }

    return 0;
}