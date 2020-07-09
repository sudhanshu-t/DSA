#include <iostream>
using namespace std;

int main(int argc, char** argv){
    int a[3][5] = {
        {11,12,13,14,15},
        {21,22,23,24,25},
        {31,32,33,34,35}
    };

    int r = sizeof(a) / sizeof(a[0]);
    int c = sizeof(a[0]) / sizeof(int);

    int total = r * c;

    int minr = 0, minc = 0, maxr = r-1, maxc = c-1;
    while(total!=0){
        // Left wall - towards down
        for(int i = minr; i <= maxr && total!=0; i++){
            cout << a[i][minc] << " ";
            total--;
        }
        minc++;

        // South wall - towards right
        for(int i = minc; i <= maxc && total!=0; i++){
            cout << a[maxr][i] << " ";
            total--;
        }
        maxr--;

        // Right wall - towards up
        for(int i = maxr; i >= minr && total!=0; i--){
            cout << a[i][maxc] << " ";
            total--;
        }
        maxc--;

        // North wall - towards left
        for(int i = maxc; i >= minc && total!=0;i--){
            cout << a[minr][i] << " ";
            total--;
        }
        minr++;
    }
}