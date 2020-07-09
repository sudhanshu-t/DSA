#include <iostream>
using namespace std;

int main(int argc, char** argv){
    int a[2][3] = {{1,2,3}, {4,5,6}};
    int b[3][4] = {{0,1,2,3}, {1,2,3,4}, {2,3,4,5}};

    int r1 = sizeof(a) / sizeof(a[0]);
    int c1 = sizeof(a[0])/ sizeof(int);

    int r2 = c1;
    int c2 = sizeof(b[0]) / sizeof(int);

    int c[r1][c2];

    for(int i = 0; i < r1; i++){
        for(int j = 0; j < c2; j++){
            c[i][j]  = 0;
        }
    }

    for(int i = 0; i < r1; i++){
        for(int k = 0; k < c2; k++){
            for(int j = 0; j < c1; j++){
                c[i][k] += a[i][j] * b[j][k];
            }
        }
    }

    for(int i = 0; i < r1; i++){
        for(int j = 0; j < c2; j++){
            cout << c[i][j] << " ";
        }

        cout << endl;
    }

    cout << endl;
}