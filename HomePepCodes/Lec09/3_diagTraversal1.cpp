#include <iostream>
using namespace std;

int main(int argc, char** argv){
    int a[][5] = {
        {1,2,3,4,5},
        {2,3,4,5,6},
        {3,4,5,6,7},
        {4,5,6,7,8},
        {5,6,7,8,9}
    };

    int r = sizeof(a) / sizeof(a[0]);
    int c = sizeof(a[0]) / sizeof(int);

    int minr = 0, minc = 0, maxr = r - 1;

    while(maxr >= 0){
        minc = r - maxr - 1;
        minr = 0;

        while(minr <= maxr){
            cout << a[minr][minc] << " ";

            minr++;
            minc++;
        }

        maxr--;
    }

    cout << endl;

    return 0;
}