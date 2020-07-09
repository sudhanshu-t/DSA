#include <iostream>
using namespace std;

int main(int argc, char** argv){
    int a[][5] = {
        {1,2,3,4,5},
        {2,3,4,5,6},
        {13,4,5,6,7},
        {4,15,6,7,8},
        {5,6,17,8,9}
    };

    int r = sizeof(a) / sizeof(a[0]);
    int c = sizeof(a[0]) / sizeof(int);

    int minc = 0, minr = 0, maxc = c - 1;

    while(maxc >= 0){
        minr = c - maxc - 1;
        minc = 0;

        while(minc <= maxc){
            cout << a[minr][minc] << " ";

            minr++;
            minc++;
        }

        maxc--;
    }

    cout << endl;
    return 0;
}