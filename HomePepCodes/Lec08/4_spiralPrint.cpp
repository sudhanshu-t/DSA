#include <iostream>
using namespace std;

int main(int argc, char** argv){
    int a[][5] = {
        {1,12,11,10,9},
        {2,13,14,15,8},
        {3,4,5,6,7}
    };

    int r = sizeof(a) / sizeof(a[0]);
    int c = sizeof(a[0]) / sizeof(int);

    int total = r * c;
    int minr = 0, minc = 0, maxr = r, maxc = c;

    while(total != 0){
        // Going down
        for(int i = minr; (i < maxr) && (total != 0); i++){
            cout << a[i][minc] << " ";
            total--;
        }

        minc++;

        // Going right
        for(int j = minc; j < maxc && (total != 0); j++){
            cout << a[maxr - 1][j] << " ";
            total--;
        }

        maxr--;

        // Going up
        for(int i = maxr - 1; i >= minr && (total != 0); i--){
            cout << a[i][maxc - 1] << " ";
            total--;
        }

        maxc--;

        // going left
        for(int j = maxc - 1; j >= minc && (total != 0); j--){
            cout << a[minr][j] << " ";
            total--;
        }

        minr++;
    }

    cout << endl;
    return 0;
}