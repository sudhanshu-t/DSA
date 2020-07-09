#include <iostream>
using namespace std;

void swap(int a[4][4], int i, int j){
    int t = a[i][j];
    a[i][j] = a[j][i];
    a[j][i] = t;
}

void swapRow(int a[][4], int i, int j){
    int r = sizeof(a) / sizeof(a[0]);

    int t = a[i][j];
    a[i][j] = a[i][r - j - 1];
    a[i][r - j - 1] = t;
}

int main(int argc, char** argv){
    int a[4][4] = {
        {1,2,3,4},
        {0,9,8,7},
        {1,2,3,4},
        {0,1,2,3}
    };

    int r = sizeof(a) / sizeof(a[0]);

    int minr = 0;
    int minc = 0;

    // Taking transpose
    for(int i = minr; i < r; i++){
        for(int j = minc; j < r; j++){
            swap(a, i, j);
        }

        minr++;
        minc++;
    }
    
    for(int i = 0; i < r; i++){
        int j = 0, k = r-1;
        while(j < k){
            swapRow(a, i, j);
            j++;
            k--;
        }
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < r; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    return 0;
}