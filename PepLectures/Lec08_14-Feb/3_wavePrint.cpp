#include <iostream>
using namespace std;

int main(int argc, char** argv){
    int a[3][5] = {{11,12,13,14,15}, {21,22,23,24,25}, {31,32,33,34,35}};

    int r = sizeof(a) / sizeof(a[0]);
    int c = sizeof(a[0]) / sizeof(int);

    int j = 0;
    for(int i = 0; i < c; i++){
        if ((i & 1) == 0){
            for(int j = 0; j < r; j++){
                cout << a[j][i] << " ";
            }
        } else {
            for(int j = r - 1; j >= 0; j--){
                cout << a[j][i] << " ";
            }
        }
    }

    cout << endl;

    return 0;
}