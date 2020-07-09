#include <iostream>
using namespace std;

int main(int argc, char** argv){
    int a[][3] = {
        {1,12,11},
        {2,13,14},
        {3,4,5}
    };

    int r = sizeof(a) / sizeof(a[0]);
    int c = sizeof(a[0]) / sizeof(int);

    int minc = 0;

// Taking transpose of A ================================

    for(int i = 0; i < r; i++){
        for(int j = minc; j < c; j++){
            int t = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = t;
        }

        minc++;
    }

// Row-wise reverse the matrix ==========================
    
    int left, right;
    
    for(int i = 0; i < r; i++){
        left = 0;
        right = c - 1;

        while(left < right){
            int t = a[i][left];
            a[i][left] = a[i][right];
            a[i][right] = t;

            left++;
            right--;
        }
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout << a[i][j] << " ";
        }

        cout << endl;
    }
}